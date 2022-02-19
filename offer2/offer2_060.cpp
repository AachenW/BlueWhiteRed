#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <unordered_map>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-21 22:36:26
author: edinw
@
*/

/*
**  注意：本题与主站 347 题相同：https://leetcode-cn.com/problems/top-k-frequent-elements/
** 
**  给定一个整数数组 nums 和一个整数 k ，请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        // 计算nums中各个元素出现的频率
        std::unordered_map<int, int> freq;
        for (const auto num: nums) {
            ++freq[num];
        }
        auto cmp = [](const std::pair<int, int> &pr1, const std::pair<int, int> &pr2) -> bool {
            return pr1.second > pr2.second;
        };

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> q(cmp);
        for (const auto &pair: freq) {
            q.emplace(pair);
            if (q.size() > k) {
                q.pop();
            }
        }
        std::vector<int> ans;
        while (!q.empty()) {
            ans.emplace_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};

class Solution2 {
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> occurrences;
        for (const auto &num: nums) {
            ++occurrences[num];
        }

        std::vector<std::pair<int, int>> values;
        for (const auto &kv: occurrences) {
            values.emplace_back(kv);
        }
        std::vector<int> ret;
        qsort(values, 0, values.size() - 1, ret, k);
        return ret;
    }

private:
    void qsort(std::vector<std::pair<int, int>> &v, int start, int end, std::vector<int> &ret, int k) {
        int picked = rand() % (end - start + 1) + start;
        std::swap(v[picked], v[start]);

        int pivot = v[start].second;
        int left = start + 1, right = end;
        while (left < right) {
            while (v[right].second <= pivot && left < right) {
                --right;
            }
            while (v[left].second >= pivot && left < right) {
                ++left;
            }
            if (left < right) {
                std::swap(v[left], v[right]);
            }
        }
        std::swap(v[start], v[left]);

        if (k <= left - start) {
            qsort(v, start, left - 1, ret, k);
        } else {
            for (int i = start; i <= left; ++i) {
                ret.emplace_back(v[i].first);
            }
            if (k > left - start + 1) {
                qsort(v, left + 1, end, ret,k - (left - start + 1));
            }
        }
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 1, 1, 2, 2, 3};
    int k = 2;
    auto ans = leetcode_cpp::Solution2().topKFrequent(nums, k);
    for (const auto &num: ans) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}