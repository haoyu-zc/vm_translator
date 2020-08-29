#include "file.h"
#include <iostream>
#include <filesystem>

using std::invalid_argument;
namespace fsys = std::filesystem;

// Return a string of file extension
std::string getExtension(const std::string &filepath)
{
    auto path = fsys::path(filepath);
    if (!path.has_extension())
        throw invalid_argument("Path " + path.string() + " has no extension.");
    return path.extension().string();
}

// Return a string of filename with extension, removing the former path
std::string getNameStem(const std::string &filepath)
{
    auto path = fsys::path(filepath);
    return path.stem().string();
}

// Return a full path without extension
std::string rmExtension(const std::string &filepath)
{
    size_t pos2 = filepath.rfind(".");
    return filepath.substr(0, pos2);
}

std::string getName(const std::string &filepath)
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
    std::string ext = getExtension(filepath);
    if (ext != ".cpp" && ext != "cc" && ext != ".s" && ext != ".o" && ext != ".a")
        throw invalid_argument("bad file name format: " + getName(filepath));
}