#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> numberOfLines(std::vector<int>& widths, std::string s) {
        int wSize = widths.size();
        int sLen = s.length();

        int spaceholder = 0, line = 1;
        for (int i = 0; i < sLen; ++i) {
            spaceholder += widths[s[i] - 'a'];
            if (spaceholder > 100) {
                spaceholder = widths[s[i] - 'a'];
                ++line;
            }
        }

        return {line, spaceholder};
    }
};
}