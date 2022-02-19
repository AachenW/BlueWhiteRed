#include <vector>
#include <string>
#include <iostream>
/*
@
projetc: leetcode
time: 2022-01-06 19:56:27
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string simplifyPath(std::string path) {
        auto split = [] (const std::string &s, const char delim) ->std::vector<std::string> {
            std::vector<std::string> ans;
            std::string cur;
            for (const auto &ch : s) {
                if (ch == delim) {
                    ans.push_back(std::move(cur));
                    cur.clear();
                } else {
                    cur += ch;
                }
            }
            ans.push_back(std::move(cur));
            return ans;
        };

        // 按"/"将路径解析成子目录，并存放到names中
        std::vector<std::string> names = split(path, '/');
        std::vector<std::string> stack;
        for (const auto &name: names) {
            // 如果当前目录为".."，则弹出stack栈顶元素，即返回上一级文件目录
            if (name == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            // 否则，只要name元素不为""时将name压入栈中
            // 子目录为"."时，表示当前文件目录，直接跳过 
            else if (!name.empty() && name != ".") {
                stack.push_back(std::move(name));
            }
        }

        std::string ans;
        // 将栈中元素按序生成简化后的路径
        if (stack.empty()) {
            ans = "/";
        } else {
            for (const auto &name: stack) {
                ans += "/" + std::move(name);
            }
        }
        return ans;
    }
};
}

int main (int argc, char **argv) {
    std::string s {"/a/./b/../../c/"};
    std::cout << leetcode_cpp::Solution().simplifyPath(s) << std::endl;
    return 0;
}