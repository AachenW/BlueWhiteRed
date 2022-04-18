#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-04-01 09:10:34
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool canReorderDoubled(std::vector<int> &arr) {
        std::unordered_map<int, int> cnt;
        for (int num: arr) {
            ++cnt[num];
        }
        if (cnt[0] & 1) {   // 对于 arr 中的 0，它只能与 0 匹配。如果 cnt[0] 是奇数，那么必然无法满足题目要求。
            return false;
        }
        
        std::vector<int> vals(cnt.size());
        for (auto &[x, _]: cnt) {
            vals.emplace_back(x);
        }
        std::sort(vals.begin(), vals.end(), [] (int a, int b) {
            return std::abs(a) < std::abs(b);
        });

        for (int num: vals) {
            if (cnt[num * 2] < cnt[num]) {  // 无法找到足够的 2x 与 x 配对
                return false;
            }
            cnt[num * 2] -= cnt[num];   // 将所有 x 和 cnt[x] 个 2x 从 arr 中去掉，继续判断剩余元素是否满足题目要求
        }

        return true;
    }
};
}