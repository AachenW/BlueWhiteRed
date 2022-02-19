#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <unordered_map>
#include <queue>
#include <random>
/*
@
LeetCode 主站
time: 2022-02-06 22:55:00
author: edinw
@
*/

/*
**  Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

namespace leetcode_cpp {
class Solution {
    using pii = std::pair<int, int>;
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> freq;
        for (const auto &num: nums) {
            ++freq[num];
        }

        auto cmp = [](const pii &p1, const pii &p2) {
            return p1.second > p2.second;
        };

        std::priority_queue<pii, std::vector<pii>, decltype(cmp)> pq(cmp);

        for (auto &[num, cnt]: freq) {
            if (pq.size() >= k) {
                if (pq.top().second < cnt) {
                    pq.pop();
                    pq.emplace(num, cnt);
                }
            } else {
                pq.emplace(num, cnt);
            }
        }

        std::vector<int> ans;
        while (!pq.empty()) {
            ans.emplace_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

class Solution2 {
    using pii = std::pair<int, int>;
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> freq;
        for (const auto &num: nums) {
            ++freq[num];
        }


        std::vector<pii> values;
        for (const auto &pair: freq) {
            values.emplace_back(pair);
        }

        std::vector<int> ans;
        qsort(values, 0, values.size() - 1, ans, k);
        return ans;
    }

private:
    void qsort(std::vector<pii> &values, int lo, int hi, std::vector<int> &ans, int k) {
        int picked = rand() % (hi - lo + 1) + lo;
        std::swap(values[picked], values[lo]);
        
        int pivot = values[lo].second;
        int left = lo, right = hi;
        while (left < right) {
            while (left < right && values[right].second <= pivot) {
                --right;
            }
            while (left < right && values[left].second >= pivot) {
                ++left;
            }
            std::swap(values[left], values[right]);
        }
        std::swap(values[left], values[lo]);

        if (k <= left - lo) {
            qsort(values, lo, left - 1, ans, k);
        } else {
            for (int i = lo; i <= left; ++i) {
                ans.emplace_back(values[i].first);
            }
            if (k > left - lo + 1) {
                qsort(values, left + 1, hi, ans, k - left + lo - 1);
            }
        }
    }
};
}