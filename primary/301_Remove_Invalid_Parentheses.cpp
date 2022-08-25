#include <bits/stdc++.h>
/*
@
projetc: leetcode
time: 2022-04-19 10:19:08
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> removeInvalidParentheses(std::string &s) {
        auto countParentheses = [&] () -> std::pair<int, int> {
            int lremove = 0, rremove = 0;
            for (char c: s) {
                if ('(' == c) {
                    ++lremove;
                } else if (')' == c){
                    if (0 == lremove) {
                        ++rremove;
                    } else {
                        --lremove;
                    }
                }
            }

            return {lremove, rremove};
        };

        auto isValid = [] (const std::string &s) -> int {
            int cnt = 0;
            for (int i=0; i<s.length(); ++i) {
                if ('(' == s[i]) {
                    ++cnt;
                } else if (')' == s[i]) {
                    --cnt;
                    if (cnt < 0) {
                        return false;
                    }
                }
            }

            return 0 == cnt;
        };

        auto [lremove, rremove] = countParentheses();
        
        std::vector<std::string> ans;
        std::function<void(std::string, int, int, int)> backtrack = [&] (std::string s, int start, int lremove, int rremove) {
            if (0 == lremove && 0 == rremove) {
                if (isValid(s)) {
                    ans.emplace_back(s);
                }
                return;
            }
            
            int sLen = s.length();
            for (int i=start; i<sLen; ++i) {
                if (i != start && s[i] == s[i - 1]) {
                    continue;
                }

                if (lremove + rremove > sLen - i) {
                    return;
                }
                if (lremove > 0 && '(' == s[i]) {
                    backtrack(s.substr(0, i) + s.substr(i + 1), i, lremove - 1, rremove);
                }
                if (rremove > 0 && ')' == s[i]) {
                    backtrack(s.substr(0, i) + s.substr(i + 1), i, lremove, rremove - 1);
                }
            }
        };

        backtrack(s, 0, lremove, rremove);

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"()())()"};

    auto ans = leetcode_cpp::Solution().removeInvalidParentheses(s);

    for (auto s: ans) {
        std::cout << s << '\n';
    }

    return 0;
}
