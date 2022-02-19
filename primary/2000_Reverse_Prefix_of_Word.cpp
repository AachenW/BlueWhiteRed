#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
/*
@
project: Leetcode
time: 2022-02-02 20:39:19
author: edinw
@
*/

/*
**  Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence 
**      of ch (inclusive). If the character ch does not exist in word, do nothing.
**  For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string 
**      will be "dcbaefd".
**  Return the resulting string.
*/

namespace leetcode_cpp{
class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        int wLen = word.length();
        int prefixIndex = -1;
        
        for (int i = 0; i < wLen; ++i) {
            if (ch == word[i]) {
                prefixIndex = i;
                break;
            }
        }
        if (-1 != prefixIndex) {
            std::reverse(word.begin(), word.begin() + prefixIndex + 1);
        }
        return word;
    }
};
}

int main(int argc, char **argv) {
    std::string word{"abcd"};
    char ch = 'z';
    std::cout << leetcode_cpp::Solution().reversePrefix(word, ch) << std::endl;
    return 0;
}