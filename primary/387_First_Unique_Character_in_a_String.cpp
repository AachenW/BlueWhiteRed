#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-20 16:40:41
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<int, int> frequency;
        for (char ch: s) {
            ++frequency[ch];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (frequency[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"leetcode"};

    std::cout << leetcode_cpp::Solution().firstUniqChar(s) << std::endl;

    return 0;
}