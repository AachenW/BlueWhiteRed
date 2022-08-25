#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-06-15 23:49:19 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        int sIdx = s.length() - 1;
        int tIdx = t.length() - 1;
        int sSkip = 0, tSkip = 0;

        while (sIdx >= 0 || tIdx >= 0) {
            while (sIdx >= 0) {
                if ('#' == s[sIdx]) {
                    ++sSkip;
                    --sIdx;
                } else if (sSkip > 0) {
                    --sSkip;
                    --sIdx;
                } else {
                    break;
                }
            }

            while (tIdx >= 0) {
                if ('#' == t[tIdx]) {
                    ++tSkip;
                    --tIdx;
                } else if (tSkip > 0) {
                    --tSkip;
                    --tIdx;
                } else {
                    break;
                }
            }
            
            if (sIdx >= 0 && tIdx >= 0) {
                if (s[sIdx] != t[tIdx]) 
                    return false;
            } else {
                if (sIdx >= 0 || tIdx >= 0) 
                    return false;
            }
            --sIdx, --tIdx;
        }

        return true;
    }  
};
}

int main(int argc, char **argv) {
    std::string s{"ab##"};
    std::string t{"c#d#"};

    std::cout << std::boolalpha << leetcode_cpp::Solution().backspaceCompare(s, t) << std::endl;

    return 0;

}
