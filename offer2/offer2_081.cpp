#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>
#include <limits.h>

/*
@
LeetCode 剑指offerⅡ
time: 2021-12-20 21:08:48
author: edinw
@
*/

/*
给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。

candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。 

对于给定的输入，保证和为 target 的唯一组合数少于 150 个。
*/
namespace leetcode_cpp {
class Solution{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> path;
        dfs(candidates, path, target, 0, 0);
        return ans;
    }

private:
    std::vector<std::vector<int>> ans;
    void dfs(std::vector<int> &candidates, std::vector<int> &path, int target, int pos, int sum) {
        if (sum >= target) {
            if (sum == target) {
                ans.emplace_back(path);
            }
            return;
        }
        for (int i = pos; i < candidates.size(); ++i) {
            path.emplace_back(candidates[i]);
            dfs(candidates, path, target, i, sum + candidates[i]);
            path.pop_back();
        }
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> candidates {2, 3, 6, 7};
    int target = 7;
    auto ans = leetcode_cpp::Solution().combinationSum(candidates, target);
    for (const auto &output : ans) {
        for (const auto &i : output) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}