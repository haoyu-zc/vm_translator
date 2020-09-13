#pragma once
#include <string>
#include <filesystem>

namespace fsys = std::filesystem;

std::string getExtension(const std::string &filepath);

std::string getNameStem(const std::string &filepath);

std::string getName(const std::string &filepath);

void validateFileName(const std::string &filepath);

std::string rmExtension(const std::string &filepath);
