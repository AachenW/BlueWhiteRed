#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-31 20:33:59
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> lexicalOrder(int n) {
        std::vector<int> ans;

        std::function<void(int)> backtrack = [&] (int idx) {
            if (idx > n) {
                return;
            }

            ans.emplace_back(idx);
            for (int i = 1; i < 10; ++i) {
                if (idx * 10 + i > n) {
                    return;
                }
                backtrack(idx * 10 + i);
            }
        };

        for (int i = 1; i < 10; ++i) {
            backtrack(i);
        }

        return ans;
    }
};
}