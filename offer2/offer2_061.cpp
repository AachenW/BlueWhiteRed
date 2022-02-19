#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <map>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-21 22:36:26
author: edinw
@
*/

/*
**  注意：本题与主站 373 题相同：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/
** 
**  给定两个以升序排列的整数数组 nums1 和 nums2 , 以及一个整数 k 。
**  定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
**  请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        auto cmp = [&nums1, &nums2] (const std::pair<int, int> &pr1, const std::pair<int, int> &pr2) -> bool {
            return nums1[pr1.first] + nums2[pr1.second] > nums1[pr2.first] + nums2[pr2.second];
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < std::min(k, m); ++i) {
            q.emplace(i, 0);
        }
        std::vector<std::vector<int>> ans;
        while (k-- > 0 && !q.empty()) {
            auto [x, y] = q.top();
            q.pop();
            ans.emplace_back(std::initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n) {
                q.emplace(x, y + 1);
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        // 滑动窗口即可计算出两个数组中满足数对和小于等于目标值 target 的数对有多少个
        auto count = [&](int target) {
            long long cnt = 0;
            int start = 0;
            int end = n - 1;
            while (start < m && end >= 0) {
                if (nums1[start] + nums2[end] > target) {
                    --end;
                } else {
                    cnt += end + 1;
                    ++start;
                }
            }
            return cnt;
        };

        /* 
        假设我们将所有「数对和」按照升序排序，两端的值分别为 l = nums1[0] + nums2[0] 和 r = nums1[n - 1] + nums2[m - 1]。因此我们可以在值域 [l, r] 上进行二分，找到第一个满足「点对和小于等于 x 的，且数量超过 k 的值 x」。
        */
        // 二分查找第k小的数对和的大小
        int left = nums1[0] + nums2[0];
        int right = nums1.back() + nums2.back();
        int pairSum = right;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (count(mid) < k) {
                left = mid + 1;
            } else {
                pairSum = mid;
                right = mid - 1;
            }
        }

        // 当二分出第 k 小的值为 x 后，由于存在不同点对的点对和值相等，我们需要先将所有点对和小于等于 x 的值加入答案，然后酌情把值等于 x 的点对加入答案，知道满足答案数量为 k。
        std::vector<std::vector<int>> ans;
        int pos = n - 1;
        /*找到小于目标值 pairSum 的数对*/
        for (int i = 0; i < m; ++i) {
            while (pos >= 0 && nums1[i] + nums2[pos] >= pairSum) {
                --pos;
            }
            for (int j = 0; j <= pos && k > 0; ++j, --k) {
                ans.emplace_back(std::initializer_list<int>{nums1[i], nums2[j]});
            }
        }

        /*找到等于目标值 pairSum 的数对*/
        pos = n - 1;
        for (int i = 0; i < m && k > 0; ++i) {
            while (pos >= 0 && nums1[i] + nums2[pos] > pairSum) {
                --pos;
            }
            for (int j = i; k > 0 && j >= 0 && nums1[j] + nums2[pos] == pairSum; --j, --k) {
                ans.emplace_back(std::initializer_list<int>{nums1[i], nums2[pos]});
            } 
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums1{1, 7, 11};
    std::vector<int> nums2{2, 4, 6};
    int k = 3;
    auto ans = leetcode_cpp::Solution().kSmallestPairs(nums1, nums2, k);
    for (const auto &pair: ans) {
        std::cout << pair[0] << " " << pair[1] << std::endl;
    }
    return 0;
}