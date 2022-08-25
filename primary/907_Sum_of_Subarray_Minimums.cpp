#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-03 17:50:53 
author: edinw
@
*/


// 这道题的本质在于找到数组中的每一个数作为最小值的范围，比如对于某个数nums[i]能够最小值以这个形式表示：左边连续m个数比nums[i]大，右边连续n个数比nums[i]大。
// 以nums[i]作为最小值的子数组的数量：m*n + m + n + 1 = (m + 1) * (n + 1)
namespace leetcode_cpp {
class Solution {
    constexpr static int BASE = 1e9 + 7;
public:
    int sumSubarrayMins(std::vector<int> &arr) {
        std::deque<int> mono_stack;
        arr.emplace_back(0);    // 保证栈中所有元素都会被弹出计算
        int aSize = arr.size();
        long ans = 0;
        for (int i = 0; i < aSize; ++i) {
            while (!mono_stack.empty() && arr[i] <= arr[mono_stack.back()]) {
                int idx = mono_stack.back(); mono_stack.pop_back();
                int prevIdx = -1;
                if (!mono_stack.empty()) prevIdx = mono_stack.back();
                int prevCnt = idx - prevIdx - 1;    // m
                int nextCnt = i - idx - 1;  // n
                ans += long(arr[idx]) * (prevCnt + 1) * (nextCnt + 1) % BASE;
                ans %= BASE;
            }
            mono_stack.emplace_back(i);
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> arr{3, 1, 2, 4};
    std::cout << leetcode_cpp::Solution().sumSubarrayMins(arr) << '\n';

    return 0;
}
