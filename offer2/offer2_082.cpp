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
time: 2021-12-20 22:26:43
author: edinw
@
*/


/*
// 给定一个可能有重复数字的整数数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合
*/
namespace leetcode_cpp {
class Solution{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::vector<int> path;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, path, target, 0, 0);
    }

private:
    void dfs(std::vector<int> &candidates, std::vector<int> &path, int target, int pos, int sum) {
        if (target == sum) {
            ans.emplace_back(path);
            return;
        }
        if (target > sum || pos == candidates.size()) {
            return;
        }

        // 不加入candidates[pos]
        dfs(candidates, path, target, getNext(candidates, pos), sum);
        // 加入candidates[pos]
        path.emplace_back(candidates[pos]);
        dfs(candidates, path, target, pos, sum + candidates[pos]);
        path.pop_back();
    }

    int getNext(std::vector<int> &candidates, int pos) {
        int cLength = candidates.size();
        for (int i = pos + 1; i < cLength; ++i) {
            if (candidates[i] != candidates[pos]) {
                return i;
            }
        }
    }
    std::vector<std::vector<int>> ans;
};
}

int main(int argc, char **argv) {
    std::vector<int> candidate{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    auto answers = leetcode_cpp::Solution().combinationSum(candidate, target);
    for (const auto &answer : answers) {
        for(const auto &i : answer) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}