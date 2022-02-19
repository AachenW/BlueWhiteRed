#include <vector>
#include <iostream>
#include <deque>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-11 19:28:00
author: edinw
@
*/

/*
注意：本题与主站 346 题相同： https://leetcode-cn.com/problems/moving-average-from-data-stream/

给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

实现 MovingAverage 类：
    MovingAverage(int size) 用窗口大小 size 初始化对象。
    double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。
*/

namespace leetcode_cpp {
class MovingAverage{
public:
    MovingAverage(int size) : size_(size) {}

    double next(int val) {
        
        nums.push_back(val);
        ans += val;
        if (nums.size() > size_) {
            ans -= nums.front();
            nums.pop_front();
        }

        return (double)ans / nums.size();
    }

private:
    int size_ {0};
    int ans {0};
    std::deque<int> nums;
};
}

int main(int argc, char **argv) {
    leetcode_cpp::MovingAverage movingAverage{1};
    std::cout << movingAverage.next(4) << " ";
    std::cout << movingAverage.next(0) << " ";
    return 0;
}