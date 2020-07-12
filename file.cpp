#include "file.h"

using std::string;
using std::invalid_argument;


string getExtension(const fs::path &filepath)
{
    //return filename.substr(filename.size() >= 2 ? filename.size() - 2 : 0);
    return filepath.extension().string();
}

string getNameStem(const fs::path &filepath)
{
    return filepath.stem().string();
}

string getName(const fs::path &filepath)
{
    return filepath.filename().string();
}

void validateFileName(const fs::path &filepath)
{
    auto ext = getExtension(filepath);
    if (ext != ".cpp" && ext != "cc" && ext != ".s" && ext != ".o" && ext != ".a")
        throw invalid_argument("bad file name format: " + getName(filepath));
}