#include <iostream>
#include <vector>

/*
@
LeetCode HOT 100
time: 2022-01-30 23:22:25
author: edinw
@
*/

/*
**  Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
*/

namespace leetcode_cpp {
class Solution {
public:
    int longestValidParentheses(std::string s) {
        int maxAns = 0, sLen = s.length();
        // initialization, dp[i] 表示以下标 i 字符结尾的最长有效括号的长度。我们将 dp 数组全部初始化为 0 。显然有效的子串一定以 ')' 结尾，因此我们可以知道以 '(' 结尾的子串对应的 dp 值必定为 0 ，我们只需要求解 ')' 在 dp 数组中对应位置的值。
        std::vector<int> dp(sLen, 0);
        
        // states transfer functions: 
        for (int i = 1; i < sLen; ++i) {
            // s[i] == ')' 需要看其前面对元素来判断是否有有效括号对
            if (')' == s[i]) {
                // Condition 1.s[i−1]== ′(′, 即s[i]和s[i−1]组成一对有效括号，有效括号长度新增长度2，i位置对最长有效括号长度为其之前2个位置的最长括号长度加上当前位置新增的2
                if ('(' == s[i - 1]) {
                    dp[i] = (i - 1 > 0 ? dp[i - 2] : 0) + 2; 
                }
                //  s[i−1]== ′)′, 这种情况下，如果前面有和s[i]组成有效括号对的字符，即形如((....))，这样的话，就要求s[i−1]位置必然是有效的括号对，否则s[i]无法和前面对字符组成有效括号对。这时，我们只需要找到和s[i]配对对位置，并判断其是否是 ( 即可。和其配对对位置为：i - dp[i - 1] - 1。如果：s[i - dp[i - 1] - 1] == '(':有效括号长度新增长度2，i位置对最长有效括号长度为 i-1位置的最长括号长度加上当前位置新增的2，那么有：dp[i] = dp[i - 1] + 2值得注意的是，i - dp[i - 1] - 1和 i 组成了有效括号对，这将是一段独立的有效括号序列，如果之前的子序列是形如 (...) 这种序列，那么当前位置的最长有效括号长度还需要加上这一段。所以：dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2
                else if (i - dp[i - 1] > 0 && '(' == s[i - dp[i - 1] - 1]) {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 1 > 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }

            maxAns = std::max(maxAns, dp[i]);
        }
        return maxAns;
    }
};

class Solution2 {
public:
    // 具体做法是始终保持栈底元素为当前已经遍历过的元素中「最后一个没有被匹配的右括号的下标」
    int longestValidParentheses(std::string s) {
        std::vector<int> stack;
        int maxAns = 0;
        // 需要注意的是，如果一开始栈为空，第一个字符为左括号的时候我们会将其放入栈中，这样就不满足提及的「最后一个没有被匹配的右括号的下标」，为了保持统一，我们在一开始的时候往栈中放入一个值为 −1 的元素。
        stack.emplace_back(-1);
        for (int i = 0; i < s.length(); ++i) {
            // 对于遇到的每个 '(' ，将它的下标放入栈中
            if ('(' == s[i]) {
                stack.emplace_back(i);
            }
            //  对于遇到的每个 ')' 
            else {
                // 先弹出栈顶元素表示匹配了当前右括号
                stack.pop_back();
                // 如果栈为空，说明当前的右括号为没有被匹配的右括号，将其下标放入栈中来更新之前提到的「最后一个没有被匹配的右括号的下标」
                if (stack.empty()) {
                    stack.emplace_back(i);
                }
                // 如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」
                else {
                    maxAns = std::max(maxAns, i - stack.back());
                }
            }
        }
        return maxAns;
    }
};

class Solution3 {
public:
    int longestValidParentheses(std::string s) {
        int left = 0, right = 0, maxLength = 0;
        int sLen = s.length();
        // 从左到右遍历字符串
        for (int i = 0; i < sLen; ++i) {
            if ('(' == s[i]) {
                ++left; // 对于遇到的每个 '('，增加 left 计数器
            } else {
                ++right;        //  对于遇到的每个 ')'，增加 right 计数器
            }
            // 每当 left 计数器与 right 计数器相等时
            if (left == right) {
                maxLength = std::max(maxLength, left + right);      // 计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串
            } else if (right > left) {
                // 当 right 计数器比 left 计数器大时，我们将 left 和 right 计数器同时变回 0
                left = 0;
                right = 0;
            }
        }
        /*  
        **  这样的做法贪心地考虑了以当前字符下标结尾的有效括号长度，每次当右括号数量多于左括号数量的时候之前的字符我们都扔掉不再考虑，重新从下一个字符开始计算，但这样会漏掉一种情 
        **      况，就是遍历的时候左括号的数量始终大于右括号的数量，即 (() ，这种时候最长有效括号是求不出来的。
        **  解决的方法也很简单，我们只需要从右往左遍历用类似的方法计算即可，只是这个时候判断条件反了过来:
        **      当 left 计数器比 right 计数器大时，我们将 left 和 right 计数器同时变回 0 
        **      当 left 计数器与 right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串
        */
        left = 0, right = 0;
        for (int i = sLen - 1; i >= 0; --i) {
            if (')' == s[i]) {
                ++right;
            } else {
                ++left;
            }
            if (left == right) {
                maxLength = std::max(maxLength, left + right);
            } else if (right < left) {
                left = 0;
                right = 0;
            }
        }
        return maxLength;
    }
};
}

int main(int argc, char **argv) {
    std::string s{")()())"};
    std::cout << leetcode_cpp::Solution3().longestValidParentheses(s) << std::endl;
    return 0;
}