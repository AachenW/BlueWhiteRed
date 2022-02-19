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
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (countTime(piles, mid) <= h) {
                if (mid == 1 || countTime(piles, mid - 1) > h) {
                    return mid;
                } else {
                    hi = mid - 1;
                }
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }

private:
    int countTime(std::vector<int> &piles, int k) {
        int t = 0;
        for (const auto &bananas: piles) {
            t += bananas / k;
            t += (bananas % k) > 0;
        }
        return t;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> piles{312884470};
    int h = 968709470;
    std::cout << leetcode_cpp::Solution().minEatingSpeed(piles, h) << std::endl;
    return 0;
}