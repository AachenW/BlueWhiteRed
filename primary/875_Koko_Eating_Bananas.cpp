#include <iostream>
#include <vector>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-25 19:44:17
author: edinw
@
*/

/*
**  注意：本题与主站 875 题相同： https://leetcode-cn.com/problems/koko-eating-bananas/
** 
**  Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
**  Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
**  Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
**  Return the minimum integer k such that she can eat all the bananas within h hours.
*/

namespace leetcode_cpp {
class Solution {
public:
    int minEatingSpeed(std::vector<int> &piles, int h) {
        int lo = 1;
        int hi = *std::max_element(piles.begin(), piles.end());

        int k = hi;
        while (lo < hi) {
            int speed = lo + ((hi - lo) >> 1);
            long time = countTime(pile, speed);
            if (time <= h) {
                k = speed;
                hi = speed;
            } else {
                lo = speed + 1;
            }
        }
        return k;
    }

private:
    int countTime(std::vector<int> &piles, int k) {
        long time = 0;
        for (const auto &bananas: piles) {
            // 计吃掉每堆香蕉的时间 
            int curTime = (bananas + speed - 1) / speed;
            time += curTime;
        }
        return time;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> piles{312884470};
    int h = 968709470;
    std::cout << leetcode_cpp::Solution().minEatingSpeed(piles, h) << std::endl;
    return 0;
}
