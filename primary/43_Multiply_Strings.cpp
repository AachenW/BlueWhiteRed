#include <iostream>
#include <vector>
#include <deque>
/*
@
time: 2022-02-18 20:55:21
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        int m = num1.size(), n = num2.size();
        std::string res(m + n, '0');
        if (0 == m || 0 == n) {
            return "0";
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int tmp = (num1[i] - '0') * (num2[j] - '0');
                tmp += res[i + j + 1] - '0';
                res[i + j + 1] = tmp % 10 + 48;
                res[i + j] = res[i + j] - '0' + tmp / 10 + 48;
            }
        }

        int idx = 0;
        while (idx < m + n - 1 && res[idx] == '0') {
            ++idx;
        }
        return res.substr(idx);
    }
};
}

int main(int argc, char **argv) {
    std::string num1{"123"}, num2{"456"};
    std::cout << leetcode_cpp::Solution().multiply(num1, num2) << std::endl;
    return 0;
}