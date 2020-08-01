#pragma once
#include <string>

using std::string;

string getExtension(const std::string &filepath);

std::string getNameStem(const std::string &filepath);

string getName(const std::string &filepath);

void validateFileName(const std::string &filepath);
