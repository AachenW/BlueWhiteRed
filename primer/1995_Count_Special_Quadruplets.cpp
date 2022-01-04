#include <vector>
#include <unordered_map>
#include <iostream>

/*
@
project: Leetcode
time: 2021-12-29 21:59:24
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int countQuadruplets(std::vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        std::unordered_map<int, int> cnt;
        /*
        在枚举前两个下标 a, b时，我们可以先逆序枚举b。在b 减小的过程中, c的取值范围是逐渐增大的：即从b+1减小到b时, c的取值范围中多了b+1这一项，而其余的项不变。因此我们只需要将所有满足c=b+1且 d>c的c,d 对应的nums[d] - nums[c]加入哈希表即可。
        */
        for (int b = n - 3; b >= 1; --b) {
            for (int d = b + 2; d < n; ++d) {
                ++cnt[nums[d] - nums[b + 1]];
            }
            for (int a = 0; a < b; ++a) {
                if (int sum = nums[a] + nums[b]; cnt.count(sum)) {
                    ans += cnt[sum];
                }
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 1, 1, 3, 5};
    std::cout << leetcode_cpp::Solution().countQuadruplets(nums) << std::endl;
    return 0;
}