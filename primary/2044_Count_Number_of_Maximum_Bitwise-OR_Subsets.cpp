#include <iostream>
#include <vector>
#include <functional>

namespace leetcode_cpp {
class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int nSize = nums.size();

        int maxOrVal = 0;
        int cnt = 0;
        std::function<void(int, int)> backtrack = [&] (int pos, int orVal) {
            if (pos == nSize) {
                if (orVal > maxOrVal) {
                    maxOrVal = orVal;
                    cnt = 1;
                } else if (orVal == maxOrVal) {
                    ++cnt;
                }
                return;
            }

            backtrack(pos + 1, orVal | nums[pos]);
            backtrack(pos + 1, orVal);
        };

        backtrack(0, 0);

        return cnt;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{2, 2, 2};

    int ans = leetcode_cpp::Solution().countMaxOrSubsets(nums);

    std::cout << ans << std::endl;

    return 0;
}