#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

/*
@
project: leetcode
time: 2022-03-05 13:07:16
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isAlienSorted(std::vector<std::string> &words, std::string &order) {
        std::unordered_map<int, int> orderHash;

        for (int i = 0; i < order.size(); ++i) {
            orderHash[order[i]] = i;
        }

        auto alienSort = [&](std::string &word1, std::string &word2) -> int {
            int wLen1 = word1.length(), wLen2 = word2.length();
            int len = wLen1 > wLen2 ? wLen1 : wLen2;

            for (int i = 0; i < len; ++i) {
                if (i >= wLen2 && i < wLen1) {
                    return 1;
                } else if (i >= wLen1 && i < wLen2) {
                    return -1;
                }
                if (orderHash[word1[i]] == orderHash[word2[i]]) {
                    continue;
                } else if (orderHash[word1[i]] < orderHash[word2[i]]) {
                    return -1;
                } else {
                    return 1;
                }
            }

            return 0;
        };
        
        int wSize = words.size();
        for (int i = 0; i < wSize; ++i) {
            for (int j = i + 1; j < wSize; ++j) {
                if (alienSort(words[i], words[j]) > 0) {
                    return false;
                }
            }
        }

        return true;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::string> strs{"hello", "leetcode"};
    std::string order{"hlabcdefgijkmnopqrstuvwxyz"};

    std::cout << std::boolalpha << leetcode_cpp::Solution().isAlienSorted(strs, order) << std::endl;

    return 0;

}
