#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstddef>

template <typename T>
std::size_t wordcount(T &is)
{
    return distance(std::istream_iterator<std::string>{is}, {});
}

// Check if a string represents a number.
bool isNumber(const std::string &s);

// Remove surrounding white sapces of a string.
std::string trimOuterSpaces(const std::string &s);
std::string removeComments(const std::string &s);
