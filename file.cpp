#include "file.h"
#include <iostream>

using std::invalid_argument;
using std::string;

string getExtension(const std::string &filepath)
{
    return filepath.substr(filepath.size() >= 2 ? filepath.size() - 2 : 0);
}

// string getNameStem(const fs::path &filepath)
// {
//     return filepath.stem().string();
// }

std::string getNameStem(const std::string &filepath)
{
    size_t dotpos = filepath.rfind(".");
    // Position of the path seperater.
    // Windows
    size_t seppos = filepath.rfind("\\");
    if (seppos == std::string::npos)
    // Windows or Linux or MacOS
        seppos = filepath.rfind("/");
    if (seppos == std::string::npos)
        throw invalid_argument("Invalid input path!\n");
    return filepath.substr(seppos + 1, dotpos - seppos + 1);
}

string getName(const std::string &filepath)
{
    size_t seppos = filepath.rfind("\\");
    if (seppos == std::string::npos)
        seppos = filepath.rfind("/");
    if (seppos == std::string::npos)
        throw invalid_argument("Invalid input path!\n");
    return filepath.substr(seppos + 1);
}

void validateFileName(const std::string &filepath)
{
    auto ext = getExtension(filepath);
    if (ext != ".cpp" && ext != "cc" && ext != ".s" && ext != ".o" && ext != ".a")
        throw invalid_argument("bad file name format: " + getName(filepath));
}