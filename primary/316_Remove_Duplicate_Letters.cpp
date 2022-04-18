#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-28 19:41:20
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
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
                        visited[ans.back() - 'a'] = 0;  // 访问位清零
                        ans.pop_back(); // 若之后还有，则可以 pop
                    } else {
                        break;  // // 若之后不存在栈顶元素了，则停止 pop
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