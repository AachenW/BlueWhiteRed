#include <iostream>
#include <vector>
#include <string>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-24 19:56:13
author: edinw
@
*/

/*
**  注意：本题与主站 852 题相同：https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
** 
**  Let's call an array arr a mountain if the following properties hold: 
**      (1). arr.length >= 3
**      (2). There exists some i with 0 < i < arr.length - 1 such that:
**          1).arr[0] < arr[1] < ... arr[i-1] < arr[i]
**          2).arr[i] > arr[i+1] > ... > arr[arr.length - 1]
**  Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... **  > arr[arr.length - 1].
*/

namespace leetcode_cpp {
class Solution {
public:
    int peakIndexInMountainArray(std::vector<int> &arr) {
        int nLength = arr.size();
        if (3 > nLength) {
            return -1;
        }
        int slow = 0, fast = 1;
        while (fast < nLength) {
            if (arr[slow] < arr[fast]) {
                ++slow;
                ++fast;
            } else {
                return slow;
            }
        }
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> arr {0, 10, 5, 2};
    std::cout << leetcode_cpp::Solution().peakIndexInMountainArray(arr) << std::endl;
    return 0;

}