#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>

/*
@
project: leetcode
time: 2021-12-20 20:47:34
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    // 对数组heaters排序需要O(nlogn)，使用二分查找对每个房屋寻找距离最近的供暖器，每次二分查找需要O(logn)的时间，有m个房屋，因此需要O(mlogn)
    // 总时间复杂度是O((m+n)logn)
    // 空间复杂度是O(logn),主要是排序需要的空间
    int findRadius(std::vector<int> &houses, std::vector<int> &heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0, j = 0; i < houses.size(); ++i) {
            int curDistance = abs(houses[i] - heaters[j]);
            while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
                curDistance = std::min(curDistance, abs(houses[i] - heaters[++j]));
            }
            ans = std::max(ans, curDistance);
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> houses {1, 2, 3, 4}, heaters {1, 4};

    std::cout << leetcode_cpp::Solution().findRadius(houses, heaters) << std::endl;
    return 0;
}