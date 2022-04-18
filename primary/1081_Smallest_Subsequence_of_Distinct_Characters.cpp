#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-28 19:50:36
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string smallestSubsequence(std::string s) {
        std::vector<int> visited(26);
        std::vector<int> num(26);

        for (char ch: s) {
            ++num[ch - 'a'];
        }

        std::string ans;
        for (char ch: s) {
            if (!visited[ch - 'a']) {
                while (!ans.empty() && ans.back() > ch) {
                    if (num[ans.back() - 'a'] > 0) {
                        visited[ans.back() - 'a'] = 0;
                        ans.pop_back();
                    } else {
                        break;
                    }
                }
                ans.push_back(ch);
                visited[ch - 'a'] = 1;
            }
            --num[ch - 'a'];
        }

        return ans;
    }
};
}