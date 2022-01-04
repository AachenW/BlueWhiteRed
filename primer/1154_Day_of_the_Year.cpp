/*
@
project: leetcode
time: 2021-12-21 19:30:37
author: edinw
@
*/

#include <string>
#include <time.h>
#include <iostream>
#include <sstream>
#include <iomanip>
namespace leetcode_cpp {
class Solution{
public:
    int dayOfYear(std::string date) {
        tm t{};
        std::istringstream ss(date);
        ss >> std::get_time(&t, "%Y-%m-%d");
        mktime(&t);
        return t.tm_yday + 1;
    }
};
}

int main (int argc, char **argv) {
    std::string date = "2019-01-09";
    std::cout << leetcode_cpp::Solution().dayOfYear(date) << std::endl;

    return 0;
}