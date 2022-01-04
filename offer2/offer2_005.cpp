#include <vector>
#include <iostream>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-22 19:47:21
author: edinw
@
*/

// 
// 与318. Maximum Product of Word Lengths相同

namespace leetcode_cpp {
class Solution{
public:
    int maxProduct(std::vector<std::string> &words) {
        decltype(words.size()) wLength = words.size();
        std::vector<int> masks(wLength);
        for (int i = 0; i < wLength; ++i) {
            std::string word = words[i];
            decltype(word.size()) wordLength = word.size();
            for (int j = 0; j < wordLength; ++j) {
                masks[i] |= 1 << (word[j] - 'a');
            }
        }
        decltype(words[0].size()) maxProd = 0;
        for (int i = 0; i < wLength; ++i) {
            for (int j = i + 1; j < wLength; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    maxProd = std::max(maxProd, (decltype(maxProd))(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::string> words {"abcw","baz","foo","bar","xtfn","abcdef"};
    std::cout << leetcode_cpp::Solution().maxProduct(words) << std::endl;
    return 0;
}