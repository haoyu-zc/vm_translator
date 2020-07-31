#pragma once
#include <string>
#include <filesystem>

using std::string;
namespace fs = std::filesystem;

string getExtension(const fs::path &filepath);

string getNameStem(const fs::path &filepath);

std::string getNameStem(const std::string filepath);

string getName(const fs::path &filepath);

void validateFileName(const fs::path &filepath);
