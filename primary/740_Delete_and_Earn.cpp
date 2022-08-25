#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-04 13:34:05
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int deleteAndEarn(std::vector<int> &nums) {
        int maxn = *std::max_element(nums.begin(), nums.end());

        std::vector<int> sum(maxn + 1);
        for (int num: nums) {
            sum[num] += num;
        }

        auto rob = [&] () -> int {
            int first = sum[0];
            int second = std::max(sum[0], sum[1]);

            for (int i = 2; i <= maxn; ++i) {
                int tmp = second;
                second = std::max(second, first + sum[i]);
                first = tmp;
            }

            return second;
        };

        return rob();
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{2, 2, 3, 3, 3, 4};
    std::cout << leetcode_cpp::Solution().deleteAndEarn(nums) << '\n';
    return 0;
}
