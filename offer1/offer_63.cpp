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
time: 2021-12-07 21:31:25
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int inf = 1e9;
        int minPrice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = std::max(maxprofit, price - minPrice);  // 最大利润 为 历史最低点买入， 再计算当前卖出得到的股票利润，并保存更新后的最大利润
            minPrice = std::min(price, minPrice);   // 记录股价历史最低点
        }
        return maxprofit;
    }
};
}

int main(int argc, char** argv) {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << leetcode_cpp::Solution().maxProfit(prices) << std::endl;
}