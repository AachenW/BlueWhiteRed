#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
/*
@
projetc: leetcode
time: 2021-12-30 23:01:04
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    bool isNStraightHand(std::vector<int> &hand, int groupsize) {
        decltype(hand.size()) n = hand.size();
        // 当总数不能被groupSize整除时，直接返回false
        if (n % groupsize != 0) {
            return false;
        }
        // 排序 
        std::sort(hand.begin(), hand.end());
        std::unordered_map<int, int> cnt;
        // 生成count哈希表
        for (auto &num : hand) {
            ++cnt[num];
        }
        for (auto &num : hand) {
            // 当此次循环第一个数在哈希表中不存在时，继续下次循环
            if (!cnt.count(num)) {
                continue;
            }
            // 搜索后面的数
            for (int j = 0; j < groupsize; ++j) {
                int next = num + j;
                if (!cnt.count(next)) { // 当搜索后面的数在哈希表不存在时，直接返回false
                    return false;
                }
                --cnt[next];            // 每搜索完一个数，将对应hash表中的second-1
                if (cnt[next] == 0) {   // 当hash表中second的值为0时，直接删除对应的num
                    cnt.erase(next);
                }
            }
        }
        return true;
    }
};
}

int main(int agrc, char **argv) {
    std::vector<int> hand {1,2,3,6,2,3,4,7,8};
    std::cout << leetcode_cpp::Solution().isNStraightHand(hand) << std::endl;
    return 0;
}