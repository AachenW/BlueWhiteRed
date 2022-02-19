#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>

/*
@
project: Leetcode
time: 2021-12-17 20:48:12
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int bottle = numBottles, ans = numBottles;
        while (bottle >= numExchange) {
            bottle -= numExchange;
            ++ans;      // 换回一满瓶
            ++bottle;   // 喝完多了一个空瓶
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    int numBottles = 9, numExchange = 3;
    std::cout << leetcode_cpp::Solution().numWaterBottles(numBottles, numExchange) << std::endl;
    return 0;
}