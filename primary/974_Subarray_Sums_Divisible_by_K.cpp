#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> record{{0, 1}};    // 前缀和本身被 k 整除的情况
        int sum = 0, ans = 0;

        // 根据同余定理，只要 prefix[j] mod k == prefix[i-1] mod k，就可以保证条件成立.
        for (int num: nums) {
            sum += num;
            int modulus = (sum % k + k) % k;    // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            if (record.count(modulus)) {
                ans += record[modulus];
            }
            ++record[modulus];
        }

        return ans;
    }
};
}