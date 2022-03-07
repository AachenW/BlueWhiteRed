#include <iostream>
#include <deque>

/*
@
project: leetcode
time: 2022-03-05 15:45:45
author: edinw
@
*/

namespace leetcode_cpp {
class MovingAverage {
public:
    MovingAverage(int sz) : size(sz) {}

    double next(int val) {
        nums.emplace_back(val);
        ans += val;
        if (nums.size() > this->size) {
            ans -= nums.front();
            nums.pop_front();
        }

        return (double)ans / nums.size();
    }

private:
    int size;
    int ans;
    std::deque<int> nums;
};
}

