#include "utils.h"
#include <algorithm>

bool isNumber(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

std::string trimOuterSpaces(const std::string &s)
{
    const char whitespace[]{" \t\n"};
    const size_t first(s.find_first_not_of(whitespace));
    // Return an empty string if s contains only whitespaces
    if (std::string::npos == first)
    {
        return {};
    }
    const size_t last(s.find_last_not_of(whitespace));
    return s.substr(first, (last - first +1));
}