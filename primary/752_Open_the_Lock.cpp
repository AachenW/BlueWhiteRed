#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
#include <unordered_set>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-16 21:46:33
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int openLock(std::vector<std::string> &deadends, std::string target) {
        if ("0000" == target) {
            return 0;
        }

        // 为了避免搜索到死亡数字，我们可以使用哈希表存储 deadends 中的所有元素，这样在搜索的过程中，我们可以均摊 O(1) 地判断一个数字是否为死亡数字
        std::unordered_set<std::string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) {
            return -1;
        }

        auto num_prev = [](char x) -> char {
            return ('0' == x ? '9' : x - 1);
        };
        auto num_succ = [](char x) -> char {
            return ('9' == x ? '0' : x + 1);
        };
        // 枚举 status 通过一次旋转得到的数字
        auto get = [&](std::string &status) -> std::vector<std::string> {
            std::vector<std::string> ret;
            for (int i = 0; i < 4; ++i) {
                char num = status.at(i);
                status.at(i) = num_prev(num);
                ret.emplace_back(status);
                status.at(i) = num_succ(num);
                ret.emplace_back(status);
                status.at(i) = num;
            }
            return ret;
        };

        std::deque<std::pair<std::string, int>> queue;
        queue.emplace_back(std::make_pair("0000", 0));
        // 存储所有搜索到的状态，避免重复搜索
        std::unordered_set<std::string> seen = {"0000"};

        while (!queue.empty()) {
            auto elment = queue.front();
            queue.pop_front();
            for (auto&& next_status: get(elment.first)) {
                if (!seen.count(next_status) && !dead.count(next_status)) {
                    // 如果搜索到了 \textit{target}target，我们就返回其对应的旋转次数。
                    if (next_status == target) {
                        return elment.second + 1;
                    }
                    // 如果其没有被搜索过，我们就将 (next_status,step+1) 加入队列
                    queue.emplace_back(std::make_pair(next_status, elment.second + 1));
                    seen.insert(std::move(next_status));
                }
            }
        }

        return -1;
    }
};
}