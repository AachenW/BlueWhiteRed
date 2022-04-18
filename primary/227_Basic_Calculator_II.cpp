#include <vector>
#include <string>
#include <numeric>

/*
@
projetc: leetcode
time: 2022-03-17 15:03:51
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int calculate(std::string s) {
        std::vector<int> stack;
        char preSign = '+';     // 记录每个数字之前的运算符,对于第一个数字，其之前的运算符视为加号
        int num = 0;
        int sLen = s.length();

        for (int i = 0; i < sLen; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            // 若读到一个运算符，或者遍历到字符串末尾，即认为是遍历到了数字末尾
            if (!isdigit(s[i]) && ' ' != s[i] || i == sLen - 1) {
                switch (preSign) {
                    case '+':   // 将数字压入栈
                        stack.emplace_back(num);
                        break;
                    case '-':   // 将数字的相反数压入栈
                        stack.emplace_back(-num);
                        break;
                    case '*':   // 计算数字与栈顶元素，并将栈顶元素替换为计算结果。
                        stack.back() *= num;
                        break;
                    case '/':   // 计算数字与栈顶元素，并将栈顶元素替换为计算结果。
                        stack.back() /= num;
                        break;
                    default:
                        break;
                }
                preSign = s[i]; // 处理完该数字后，更新 preSign 为当前遍历的字符。
                num = 0;
            }
        }
        // 遍历完字符串 ss 后，将栈中元素累加，即为该字符串表达式的值。
        return std::accumulate(stack.begin(), stack.end(), 0);
    }
};
}