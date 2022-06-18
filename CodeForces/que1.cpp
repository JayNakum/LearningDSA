#include <string>
#include <vector>
#include <math.h>

std::vector<std::string> solution(const std::string &s)
{
    std::vector<std::string> output = std::vector<std::string>();
    int n = s.length();
    output.reserve(ceil(n / 2));
    for (int i = 1; i < n; i++)
    {
    std::string x(s[i-1]);
        x.append((s[i-1]));
        // x.append(s.at(i));
    }
    
    return {}; // Your code here
}