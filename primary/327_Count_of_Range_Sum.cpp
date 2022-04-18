#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-13 09:45:13
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int countRangeSum(std::vector<int> &nums, int lower, int upper) {
        std::vector<long long> sum(nums.size());
        
        // 求前缀和
        sum[0] = nums[0];
        for (int i=1; i<nums.size(); ++i) 
            sum[i] = sum[i-1] + nums[i];
        
        // sum[L, ..., M] merge sum[M + 1, ..., R], 返回符合条件的个数
        std::function<int(int, int, int)> merge = [&] (int L, int M, int R) -> int {
            int count = 0;
            int curLeft = L;
            int curRight = M + 1;
            
            // 左区间merge右区间之前，结算左右的答案：符合条件的下标对数量
            // 类似与滑动窗口：[left, ..., rright)窗口一直在向右滑动
            // 对于左半区间的每个sum[curLeft]，在右半区定位到符合条件的上下临界下标位置left, right
            // 当处理完一个curLeft后，再进行下一个curLeft时，区间有序，下一个curLeft必然 >= 上一个curLeft
            // 因此，右半区的窗口只须要继续往右滑动即可，始终不需要回退
            int left = M + 1;
            int right = M + 1;
            while (curLeft <= M) {
                // 对于每一个左区间元素curLeft，滑动窗口[left, ..., right)在右区，向右滑档，覆盖符合条件的范围
                while (left <= R && sum[left] - sum[curLeft] < lower) ++left;
                while (right <= R && sum[right] - sum[curLeft] <= upper) ++right;
                
                // 此时，left来到右半区第一个符合条件(>=lower)的位置，right来到右半区第一个超出条件(>upper)的位置
                // 即：[left, right)符合条件，结算答案：对于固定的左区元素[curLeft]，满足条件的下标对数量
                count += right - left;
                ++curLeft;
            }
            
            // 结算完答案，开始mergeSort，以下是典型的归并排序merge的代码：
            std::vector<long long> tmp(R - L + 1);
            int i = 0;
            curLeft = L;
            curRight = M + 1;
            while (curLeft <= M && curRight <= R) {
                tmp[i++] = sum[curLeft] <= sum[curRight] ? sum[curLeft++] : sum[curRight++];
            }

            while (curLeft <= M) {
                tmp[i++] = sum[curLeft++];
            }
            while (curRight <= R) {
                tmp[i++] = sum[curRight++];
            }

            for (i = 0; i <= R - L; ++i) {
                sum[L + i] = tmp[i];
            }

            return count;
        };
        
        // 返回sum[L, ... R]上，区间累加和满足条件的个数
        std::function<int(int, int)> processByUsingMergeSort = [&](int left, int right) -> int {
            if (left == right) {
                return (sum[left] >= lower && sum[right] <= upper) ? 1 : 0;
            }

            int mid = left + (right - left) / 2;
            int leftPartCount = processByUsingMergeSort(left, mid);
            int rightPartCount = processByUsingMergeSort(mid + 1, right);
            
            // 此时左区和右区已经分别有序，左右两区merge，结算左右整体的答案：
            int leftWithRightCount = merge(left, mid, right);

            return leftPartCount + rightPartCount + leftWithRightCount;
        };

        return processByUsingMergeSort(0, sum.size() - 1);
    }
};
}

int main(int argc, char **argv) {
    int lower = -1, upper = 0;
    std::vector<int> nums{2147483647,-2147483648,-1,0};

    std::cout << leetcode_cpp::Solution().countRangeSum(nums, lower, upper) << '\n';

    return 0;
}

