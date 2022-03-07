#include <iostream>
#include <vector>

/*
@
LeetCode
time: 2022-03-02 22:00:28
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int compress(std::vector<char> &chars) {
        int n = chars.size();
        int write = 0, left = 0;
        for (int read = 0; read < n; ++read) {
            if (read == n - 1 || chars[read] != chars[read + 1]) {
                chars[write++] = chars[read];
                int num = read - left + 1;
                if (num > 1) {
                    int anchor = write;
                    while (num > 0) {
                        chars[write++] = num % 10 + '0';
                        num /= 0;
                    }
                    std::reverse(&chars[anchor], &chars[write]);
                }
                left = read + 1;
            }
        }

        return write;
    }
};
}