#include "utils.h"
#include <algorithm>
#include <regex>

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

std::string removeComments(const std::string &s)
{
    // Remove "//" comments and spaces in the front.
    std::string pattern_comt = "\\W*//.+";
    std::regex r_comt(pattern_comt);
    std::string fmt = "";
    return regex_replace(s, r_comt, fmt);
}