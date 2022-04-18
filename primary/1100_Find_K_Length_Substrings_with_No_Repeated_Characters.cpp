#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    int numKLenSubstrNoRepeats(std::string S, int K) {
        int sLen = S.length(), ans = 0;
        std::unordered_set<int> seen;
        for (int left = 0, right = 0; right < sLen; ++right) {
            while (seen.size() >= K || seen.count(S[right])) {
                seen.erase(S[left++]);
            }
            seen.insert(S[right]);
            if (seen.size() == K) {
                ++ans;
            }
        }

        return ans;
    }
};
}