#include <string>
#include <vector>
#include <iostream>

namespace leetcode_cpp {
class Solution {
public:
    int evalRPN(std::vector<std::string> &tokens) {
        std::vector<int> stk;
        int n = tokens.size();
        for (auto &&token: tokens) {
            if (isNumber(token)) {
                stk.emplace_back(atoi(token.c_str()));
            } else {
                int num2 = stk.back();
                stk.pop_back();
                int num1 = stk.back();
                stk.pop_back();
                switch(token[0]) {
                case '+':
                    stk.emplace_back(num1 + num2);
                    break;
                case '-':
                    stk.emplace_back(num1 - num2);
                    break;
                case '*':
                    stk.emplace_back(num1 * num2);
                    break;
                case '/':
                    stk.emplace_back(num1 / num2);
                    break;
                default:
                    break;
                }
            }
        }

        return stk.back();
    }

private:
    bool isNumber(std::string &s) {
        return !("+" == s || "-" == s || "*" == s || "/" == s);
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::string> tokens{"2", "1", "+", "3", "*"};

    std::cout << leetcode_cpp::Solution().evalRPN(tokens) << std::endl;

    return 0;
}
