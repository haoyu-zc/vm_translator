#pragma once
#include <string>

// Check if a string represents a number.
bool isNumber(const std::string &s);

// Remove surrounding white sapces of a string.
std::string trimOuterSpaces(const std::string &s);
std::string removeComments(const std::string &s);