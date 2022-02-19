#include <iostream>
#include <vector>
#include <queue>
#include <initializer_list>
/*
@
projetc: leetcode
time: 2022-01-14 19:19:38
author: edinw
@
*/

/*
给定两个以 升序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。

定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。

请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
*/

namespace leetcode_cpp {
class Solution{
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
        auto cmp = [&nums1, &nums2] (const std::pair<int, int> &a, const std::pair<int, int> &b) {
            return nums1.at(a.first) + nums2.at(a.second) > nums1.at(b.first) + nums2.at(b.second);
        };

        int m = nums1.size();
        int n = nums2.size();
        std::vector<std::vector<int>> ans;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp); 
        for (int i = 0; i < std::min(k, m); ++i) {
            // 我们可以将nums1的前k个索引数对(0,0),(1,0),…,(k−1,0)加入到队列中，每次从队列中取出元素(x,y)时，我们只需要将nums2的索引增加即可，这样避免了重复加入元素的问题。
            pq.emplace(i, 0);       
        }
        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.emplace_back(std::initializer_list<int>{nums1.at(x), nums2.at(y)});
            if (y + 1 < n) {
                pq.emplace(x, y + 1);   // 待选的索引为(x + 1, y) 和 (x, y + 1)
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
    for (const auto &nums: ans) {
        for (const auto &num: nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
