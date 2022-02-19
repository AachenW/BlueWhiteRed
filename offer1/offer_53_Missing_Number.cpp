#include <vector>
#include <string>
#include <iostream>
#include <deque>

/*
@
LeetCode 剑指offer
time: 2022-01-31 09:46:10
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int missingNumber(std::vector<int> &nums) {
        int nLength = nums.size();
        if(nLength <= 0){
            return -1;
        }
        int lo = 0, hi = nLength - 1;
        int mid = 0;
        // 二分法查找 “右子数组的首位元素”
        while (lo <= hi) {
            mid = lo + ((hi - lo) >> 1);
            if (nums[mid] != mid) {
                if(mid == 0 || nums[mid - 1] == mid - 1){  // 目标左边数据等于下标，所以满足条件
                    return mid;
                }
                hi = mid - 1;       // 若 nums[m] != m ,则 “左子数组的末位元素” 一定在闭区间 [i, m - 1] 中，因此执行 j = m - 1
            } else {    
                lo = mid + 1;       // 若 nums[m] = m ,则 “右子数组的首位元素” 一定在闭区间 [m + 1, j] 中，因此执行 i = m + 1.
            }
        }   
        if(lo == nLength){
            return nLength;
        }
        // 无效的输入，比如数组不是按要求排序的；或者有数字不在[0, n - 1]内
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {0, 2, 3};
    std::cout << leetcode_cpp::Solution().missingNumber(nums) << std::endl;
    return 0;
}
