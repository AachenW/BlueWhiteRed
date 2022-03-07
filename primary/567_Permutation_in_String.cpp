#include <vector>
#include <iostream>
#include <functional>
#include <set>
/*
@
LeetCode 剑指offerII
time: 2022-03-04 19:31:36
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int sLen1 = s1.length(), sLen2 = s2.length();
        if (sLen1 > sLen2) {
            return false;
        }

        std::vector<int> cnt(26);
        for (const char c: s1) {
            --cnt[c - 'a'];
        }

        for (int left = 0, right = 0; i < sLen2; ++i) {
            int x = s2[right] - 'a';
            ++cnt[c];
            while (cnt[c] > 0) {
                ++cnt[s2[left] - 'a'];
                ++left;
            }

            if (right - left + 1 == sLen1) {
                return true;
            }
        }

        return false;

    }
};

class Solution2 {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int sLen1 = s1.length(), sLen2 = s2.length();
        if (sLen1 > sLen2) {
            return false;
        }

        std::vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < sLen1; ++i) {
            ++cnt1[s1[i] - '0'];
            ++cnt2[s2[i] - '0'];
        }

        if (cnt1 == cnt2) {
            return true;
        }

        for (int i = sLen1; i < sLen2; ++i) {
            ++cnt2[s2[i] - '0'];
            --cnt2[s2[i - sLen1] - '0'];
            if (cnt1 == cnt2) {
                return true;
            }
        }

        return false;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"abc"};
    auto ans = leetcode_cpp::Solution().permutation(s);
    for (const auto &str: ans) {
        std::cout << str << std::endl;
    }

    return 0;
}
