#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace util
{
std::string Trim(std::string in, std::string dep);
std::vector<int> Split(std::string in, std::string dep);

//////////////////////////////////////////////////////////////////////////

std::string Trim(std::string in, char dep)
{
    if (in.size() == 0)
    {
        return in;
    }
    if (in[0] == dep)
    {
        in = in.substr(1);
    }
    if (in.size() == 0)
    {
        return in;
    }
    if (in[in.size() - 1] == dep)
    {
        in = in.substr(0, in.size() - 1);
    }
    return in;
}

std::vector<int> Split(std::string in, std::string dep)
{
    std::vector<int> out;
    std::string::size_type pos1 = 0;
    auto pos2 = in.find(dep, pos1);
    while (std::string::npos != pos2)
    {
        out.push_back(std::atoi(in.substr(pos1, pos2).c_str()));
        pos1 = pos2 + 1;
        pos2 = in.find(dep, pos1);
    }
    out.push_back(std::atoi(in.substr(pos1).c_str()));
    return out;
}
}  // namespace util
