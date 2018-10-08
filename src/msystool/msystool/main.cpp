#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h>

int main(int argc, char ** argv)
{
    std::string strArgv(MAX_PATH, '\0');
    GetModuleFileNameA(NULL, (LPSTR)strArgv.c_str(), strArgv.size());
    strArgv = strArgv.c_str();
    std::for_each(strArgv.begin(), strArgv.end(), [](auto & v){if(v=='\\') v='/';});
    std::string strPath = strArgv.substr(0, strArgv.find_last_of("/"));
    std::string strFile32 = strPath + "\\1.0-32\\etc\\fstab";
    std::string strFile64 = strPath + "\\1.0-64\\etc\\fstab";

    std::string strPath32 = strPath + "/1.0-32/TDM-GCC-32 /mingw";
    std::string strPath64 = strPath + "/1.0-64/TDM-GCC-64 /mingw";

    std::fstream f32(strFile32);
    if(f32.is_open())
    {
        std::cout << "Install msys mingw 32..." << std::endl;
        f32.write(strPath32.c_str(), strPath32.length());
        f32.close();
        std::cout << "Install msys mingw 32 complete!" << std::endl;
    }

    std::fstream f64(strFile64);
    if(f64.is_open())
    {
        std::cout << "Install msys mingw 64..." << std::endl;
        f64.write(strPath64.c_str(), strPath64.length());
        f64.close();
        std::cout << "Install msys mingw 64 complete!" << std::endl;
    }
    return 0;
}
