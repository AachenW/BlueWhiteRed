#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-08 22:51:37
author: edinw
@
*/

/*
注意：本题与主站 150 题相同： https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/

根据 逆波兰表示法，求该后缀表达式的计算结果。
有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
*/

namespace leetcode_cpp {
class Solution {
public:
    int evalRPN(std::vector<std::string> &tokens) {
        std::deque<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; ++i) {
            std::string& token = tokens[i];
            if (isNumber(token)) {
                stk.push_back(atoi(token.c_str()));
            } else {
                int num2 = stk.back();
                stk.pop_back();
                int num1 = stk.back();
                stk.pop_back();
                switch (token[0]) {
                case '+':
                    stk.push_back(num1 + num2);
                    break;
                case '-' :
                    stk.push_back(num1 - num2);
                    break;
                case '*':
                    stk.push_back(num1 * num2);
                    break;
                case '/':
                    stk.push_back(num1 / num2);
                    break;
                default:
                    break;
                }
            }
        }
        return stk.back();
    }

private:
    bool isNumber(std::string &token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};
}

int main (int argc, char **argv) {
    std::vector<std::string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout << leetcode_cpp::Solution().evalRPN(tokens) << std::endl;
    return 0; 
}