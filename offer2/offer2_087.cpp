#include <string>
#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-24 10:41:26
author: edinw
@
*/


/*
// 本题与主站 93 题相同：https://leetcode-cn.com/problems/restore-ip-addresses/ 
// 给定一个只包含数字的字符串s, 用以表示一个IP地址, 返回所有可能从s获得的有效IP地址. 你可以按任何顺序返回答案.
*/
namespace leetcode_cpp {
class Solution{
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        segments.resize(SEG_COUNT);
        backtrack(s, 0, 0);
        return ans;
    }

private:
    void backtrack(const std::string &s, int segId, int segStart) {
        // 如果找到了4段IP地址并且遍历完了字符串，那么就是一种答案
        if (segId == SEG_COUNT) {
            if (segStart == s.size()) {
                std::string ipAddr;
                for (int i = 0; i < SEG_COUNT; ++i) {
                    ipAddr.append(std::to_string(segments[i]));
                    if (i != SEG_COUNT - 1) {
                        ipAddr.append(".");
                    }
                }
                ans.push_back(std::move(ipAddr));
            }
            return;
        }

        // 如果还没有找到4段IP地址就已经遍历完了字符串，那么提前回溯
        if (segStart == s.size()) {
            return;
        }

        // 由于不能有前导0，如果当前数字为0，那么这一段IP地址只能为0
        if (s[segStart] == '0') {
            segments[segId] = 0;
            backtrack(s, segId + 1, segStart + 1);
        }

        // 一般情况，枚举每一种可能性并递归
        int addr = 0;
        typedef decltype(s.size()) sz;
        sz slength = s.size();
        for (sz segEnd = segStart; segEnd < slength; ++segEnd) {
            addr = addr * 10 + (s[segEnd] - '0');
            if (addr > 0 && addr <= 0xFF) {
                segments[segId] = addr;
                backtrack(s, segId + 1, segEnd + 1);
            } else {
                break;
            }
        }
    }

private:
    static constexpr int SEG_COUNT = 4;
    std::vector<std::string> ans;
    std::vector<int> segments;
};
}

int main(int argc, char **argv) {
    std::string s("25525511135");
    auto answers = leetcode_cpp::Solution().restoreIpAddresses(s);
    for (const auto &ans : answers) {
        std::cout << ans << std::endl;
    }

    return 0;
}