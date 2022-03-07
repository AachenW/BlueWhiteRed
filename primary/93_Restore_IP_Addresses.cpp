#include <iostream>
#include <vector>
#include <functional>

/*
@
projetc: leetcode 
time: 2022-02-28 14:29:00
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
private:
    static constexpr int SEG_COUNT = 4;
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<int> segments(SEG_COUNT);
        std::vector<std::string> ans;
        int sLen = s.length();

        std::function<void(int, int)> backtrack = [&](int segId, int segStart) {
            // 如果找到了 4 段 IP 地址并且遍历完了字符串，那么就是一种答案
            if (segId == SEG_COUNT) {
                if (segStart == sLen) {
                    std::string addr;
                    for (int i = 0; i < SEG_COUNT; ++i) {
                        addr += std::to_string(segments[i]);
                        if (i != SEG_COUNT - 1) {
                            addr += ".";
                        }
                    }
                    ans.emplace_back(addr);
                }
                return;
            }

            // 如果还没有找到 4 段 IP 地址就已经遍历完了字符串，那么提前回溯
            if (segStart == sLen) {
                return;
            }

            // 由于不能有前导零，如果当前数字为 0，那么这一段 IP 地址只能为 0
            if (s[segStart] == '0') {
                segments[segId] = 0;
                backtrack(segId + 1, segStart + 1);
            }

            // 一般情况，枚举每一种可能性并递归
            int addr = 0;
            for (int segEnd = segStart; segEnd < s.size(); ++segEnd) {
                addr = addr * 10 + (s[segEnd] - 48);
                if (addr > 0 && addr <= 0xFF) {
                    segments[segId] = addr;
                    backtrack(segId + 1, segEnd + 1);
                } else {
                    break;
                }
            }
        };

        backtrack(0, 0);

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s {"25525511135"};

    auto ans = leetcode_cpp::Solution().restoreIpAddresses(s);

    for (const auto &ip: ans) {
        std::cout << ip << std::endl;
    }

    return 0;
}