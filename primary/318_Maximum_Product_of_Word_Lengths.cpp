#include <vector>
#include <string>

/*
@
LeetCode 剑指offerII
time: 2022-03-04 15:17:49
author: edinw
@
*/

/*
**  Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two 
**      words do not share common letters. If no such two words exist, return 0.
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxProduct(std::vector<std::string>& words) {
        int wSize = words.size();
        std::vector<int> masks(wSize);

        for (int i = 0; i < wSize; ++i) {
            std::string tmp = words[i];
            int wLen = tmp.length();
            for (int j = 0; j < wLen; ++j) {
                masks[i] |= (1 << (tmp[j] - 'a'));
            }
        }

        int ans = 0;
        for (int i = 0; i < wSize; ++i) {
            for (int j = i + 1; j < wSize; ++j) {
                if (0 == (masks[i] & masks[j])) {
                    ans = std::max(ans, (int)(words[i].length() * words[j].length()));
                }
            }
        }

        return ans;
    }
};
}