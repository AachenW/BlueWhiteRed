#include <string>
#include <vector>
#include <iostream>
/*
@
project: leetcode
time: 2022-01-03 19:37:45
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    std::string dayofTheWeek(int day, int month, int year) {
        std::vector<std::string> week {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        std::vector<int> monthdays {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        // 输入年份之前的年份的天数贡献， (year - 1969) / 4 为当前年份之前所有的闰年数
        int days = 365 * (year - 1971) + (year - 1969) / 4;
        // 输入年份中，输入月份之前的月份的天数贡献
        for (int i = 0; i < month - 1; ++i) {
            days += monthdays[i];
        }
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3) {
            days += 1;
        }
        // 输入月份中的天数贡献
        days += day;
        return week[(days + 3) % 7];
    }
};
}

int main(int argc, char **argv) {
    int day = 15, month = 8, year = 1993;
    std::cout << leetcode_cpp::Solution().dayofTheWeek(day, month, year) << std::endl;
    return 0;
}