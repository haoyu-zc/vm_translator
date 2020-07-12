#pragma once
#include <string>
#include <filesystem>

using std::string;
namespace fs = std::filesystem;

string getExtension(const fs::path &filepath);

string getNameStem(const fs::path &filepath);

string getName(const fs::path &filepath);

void validateFileName(const fs::path &filepath);
