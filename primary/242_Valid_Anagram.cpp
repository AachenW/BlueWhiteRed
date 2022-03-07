#include <string>
#include <iostream>
#include <vector>

/*
@
project: leetcode
time: 2022-03-05 12:03:24
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int sLen = s.length(), tLen = t.length();
        if (sLen != tLen || s == t) {
            return false;
        }

        std::vector<int> counter(26, 0);
        
        for (const char c: s) {
            ++counter[c - 'a'];
        }

        for (const char c: t) {
            --counter[c - 'a'];
            if (counter[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"anagram"}, t{"nagaram"};

    std::cout << std::boolalpha << leetcode_cpp::Solution().isAnagram(s, t) << std::endl;

    return 0;

}
