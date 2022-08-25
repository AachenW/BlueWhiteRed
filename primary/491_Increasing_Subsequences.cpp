#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> findSubsequences(std::vector<int> &nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> seq;

        std::function<void(int)> dfs = [&] (int idx) {
            if (seq.size() > 1) res.emplace_back(seq);
            std::unordered_set<int> hash;
            for (int i = idx; i < nums.size(); ++i) {
                if ((seq.empty() || seq.back() <= nums[i]) && hash.find(nums[i]) == hash.end()) {
                    hash.insert(nums[i]);
                    seq.emplace_back(nums[i]);
                    dfs(i + 1);
                    seq.pop_back();
                }
            }
        };

        dfs(0);

        return res;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{4, 6, 7, 7};

    auto ans = leetcode_cpp::Solution().findSubsequences(nums);
    for (auto arr: ans) {
        for (int num: arr) {
            std::cout << num << ","; 
        }
        std::cout << '\n';
    }

    return 0;
}