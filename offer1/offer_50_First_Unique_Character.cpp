#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <deque>
/*
@
LeetCode 剑指offer
time: 2022-02-01 23:13:18
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    char firstUniqChar(std::string s) {
        std::unordered_map<char, int> cntHash;
        for (const auto &ch: s) {
            ++cntHash[ch];
        }

        for (int i = 0; i < s.length(); ++i) {
            if (1 == cntHash[i]) {
                return s[i];
            }
        }
        return ' ';
    }
};

class Solution2 {
public:
    char firstUniqChar(std::string s) {
        std::unordered_map<char, int> indexMap;
        int sLen = s.length();
        for (int i = 0; i < sLen; ++i) {
            char ch = s[i];
            if (indexMap.count(ch)) {
                indexMap[ch] = -1;
            } else {
                indexMap[ch] = i;
            }
        }

        int first = sLen;
        for (auto [_, index]: indexMap) {
            if (-1 != index && index < first) {
                first = index;
            }
        }
        return first == sLen ? ' ': s[first];
    }
};

class Solution3 {
public:
    char firstUniqChar(std::string s) {
        std::unordered_map<char, int> indexMap;
        std::deque<std::pair<char, int>> queue;
        int sLen = s.length();
        for (int i = 0; i < sLen; ++i) {
            char ch = s[i];
            if (!indexMap.count(ch)) {
                indexMap[ch] = i;
                queue.emplace_back(ch, i);
            } else {
                indexMap[ch] = -1;
                while (!queue.empty() && indexMap[queue.front().first] == -1) {
                    queue.pop_front();
                }
            }
        }

        return queue.empty() ? ' ': queue.front().first;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"abaccdeff"};
    std::cout << leetcode_cpp::Solution().firstUniqChar(s) << std::endl;
    return 0;
}