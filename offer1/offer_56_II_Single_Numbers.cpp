#include <vector>

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> singleNumbers(std::vector<int>& nums) {
        int nSize = nums.size();
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = 0;
            for (int j = 0; j < nSize; ++j) {
                bit += (nums[j] >> i) & 1;
            }
            ans = ans * 2 + bit % 3;
        }

        return {ans};
    }
};
}