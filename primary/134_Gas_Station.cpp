#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-02-10 22:52:00
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
        int n = gas.size();
        int i = 0;

        // 从头到尾遍历每个加油站，并且检查以该加油站为起点，能否行驶一周
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;    // 记录能走过几个站点
            while (cnt < n) {   // 退出循环的条件是走过所有的站点
                int j = (i + cnt) % n;  // 加油站是环形的
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) { // 如果这个站点发现油不够了
                    break;
                }
                ++cnt;  // 这个站点满足情况
            }
            if (cnt == n) { // 如果能环绕一圈
                return i;
            } else {    // 不行的话 从下一个站点开始 检查
                i = i + cnt + 1;
            }
        }

        return -1;  // 所有加油站作为起点都不满足
    }
};
}