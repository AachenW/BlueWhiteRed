#include <bits/stdc++.h>

/*
@
Leetcode
time: 2022-03-20 20:44:41
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string> &words, int k) {
        std::unordered_map<std::string, int> cnt;
        for (auto &&word: words) {
            ++cnt[word];
        }

        using psi = std::pair<std::string, int>; 
        auto cmp = [](const psi &a, const psi &b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };

        std::priority_queue<psi, std::vector<psi>, decltype(cmp)> pq(cmp);

        for (auto &&it: cnt) {
            pq.emplace(it);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        std::vector<std::string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = pq.top().first;
            pq.pop();
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::string> words{{"i", "love", "leetcode", "i", "love", "coding"}};
    int k = 2;
    
    auto ans = leetcode_cpp::Solution().topKFrequent(words, k);

    for (auto &&output: ans) {
        std::cout << output << std::endl;
    }

    return 0;
}