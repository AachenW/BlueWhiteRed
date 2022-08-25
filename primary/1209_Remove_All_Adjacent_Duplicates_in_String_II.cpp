#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-04 14:37:53 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string removeDuplicates(std::string s, int k) {
        std::deque<int> counts;
        int sLen = s.length();

        for (int i = 0; i < sLen; ++i) {
            if (0 == i || s[i - 1] != s[i]) {
                counts.emplace_back(1);
            } else if (++counts.back() == k){
                counts.pop_back();
                s.erase(i - k + 1, k);
                i = i - k;
            }
        }

        return s;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"deeedbbcccbdaa"};
    int k = 3;
    std::cout << leetcode_cpp::Solution().removeDuplicates(s, k) << '\n';
    return 0;
}
