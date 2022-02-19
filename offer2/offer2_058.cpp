#include <iostream>
#include <deque>
#include <vector>
#include <map>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-20 21:29:41
author: edinw
@
*/

/*
**  注意：本题与主站 729 题相同： https://leetcode-cn.com/problems/my-calendar-i/
** 
**  请实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内没有其他安排，则可以存储这个新的日程安排。
**  MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end 时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，
**  start <= x < end。
**  当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生重复预订。
**  每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true。否则，返回 false 并且不要将该日程安排添加到日历中。
*/

namespace leetcode_cpp {
class MyCalendar{
    std::map<int, int> hashMap;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto it = hashMap.lower_bound(start);
        // 与后一时间段重叠
        if (it != hashMap.end() && it->first < end) {
            return false;
        }
        // 与前一时间段重叠
        if (it != hashMap.begin() && (--it)->second > start) {
            return false;
        }
        hashMap[start] = end;
        return true;
    }
};
}

int main(int argc, char **argv) {
    leetcode_cpp::MyCalendar calendar;
    std::vector<std::vector<int>> nums {{97,100},{33,51},{89,100},{83,100},{75,92},{76,95},{19,30},{53,63},{8,23},{18,37},{87,100},{83,100},{54,67},{35,48},{58,75},{70,89},{13,32},{44,63},{51,62},{2,15}};
    for (const auto &pair: nums) {
        std::cout << std::boolalpha << calendar.book(pair[0], pair[1]) << std::endl;
    }
    return 0;
}