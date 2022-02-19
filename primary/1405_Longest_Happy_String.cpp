#include <vector>
#include <iostream>
#include <algorithm>
/*
@
project: Leetcode
time: 2022-02-07 22:03:56
author: edinw
@
*/

/*
**  A string s is called happy if it satisfies the following conditions:
**      s only contains the letters 'a', 'b', and 'c'.
**      s does not contain any of "aaa", "bbb", or "ccc" as a substring.
**      s contains at most a occurrences of the letter 'a'.
**      s contains at most b occurrences of the letter 'b'.
**      s contains at most c occurrences of the letter 'c'.
**  
**  Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If 
**      there is no such string, return the empty string "".
**
**  A substring is a contiguous sequence of characters within a string.
*/

namespace leetcode_cpp {
class Solution {
public:
    // 思路：贪心，由于我们要求字符串尽可能地长，所以尽可能选择数量多的字符。
    std::string longestDiverseString(int a, int b, int c) {
        std::string res;
        using pii = std::pair<int, int>;
        std::vector<std::pair<int, int>> arr = {{a, 'a'}, {b, 'b'}, {c, 'c'}};

        while (true) {
            // 按照字符的数量由大到小排序
            std::sort(arr.begin(), arr.end(), [](const pii &p1, const pii &p2) {
                return p1.first > p2.first;
            });
            bool hasNext = false;
            // 按照数量，来选择字符
            for (auto &[freq, ch]: arr) {
                int m = res.size();
                if (freq <= 0) {
                    break;
                }
                // 出现连续三个字符相同的，则选择下一个字符
                if (m >= 2 && res[m - 2] == ch && res[m - 1] == ch) {
                    continue;
                }
                // 选择该字符后，就需要重新排序了，然后选择下一个数量最多的字符
                hasNext = true;
                res.push_back(ch);
                --freq;
                break;
            }
            // 若三个字符都无法添加了，则表示找到最长快乐字符串了，直接退出即可
            if (!hasNext) {
                break;
            }
        }
        return res;
    }
};
}

int main(int argc, char **argv) {
    int a = 1, b = 1, c = 7;
    std::cout << leetcode_cpp::Solution().longestDiverseString(a, b, c) << std::endl;
    return 0;
}