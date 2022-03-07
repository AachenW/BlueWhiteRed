#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <functional>
#include <unordered_set>

/*
@
LeetCode 剑指offerⅡ
time: 2021-12-21 20:42:52
author: edinw
@
*/

// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

namespace leetcode_cpp {
class Solution{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        decltype(nums.size()) nLength = nums.size();
        if (0 == nLength) {
            return {};
        }
        std::vector<int> path;
        std::vector<bool> used(nLength);
        std::sort(nums.begin(), nums.end());
        backtrack(nums, path, 0, nLength, used);
        return ans;
    }

private:
    void backtrack(std::vector<int> &nums, std::vector<int> &path, int depth, int len, std::vector<bool> &used) {
        if (depth == len) {
            ans.emplace_back(path);
            return;
        }
        int prev = INT_MAX;
        for (int i = 0 ; i < len; ++i) {
            // 加上 !vis[i - 1]来去重主要是通过限制一下两个相邻的重复数字的访问顺序
            // 举个栗子，对于两个相同的数11，我们将其命名为1a1b, 1a表示第一个1，1b表示第二个1； 那么，不做去重的话，会有两种重复排列 1a1b, 
            // 1b1a， 我们只需要取其中任意一种排列； 为了达到这个目的，限制一下1a, 1b访问顺序即可。 比如我们只取1a1b那个排列的话，只有当
            // visit nums[i-1]之后我们才去visit nums[i]， 也就是如果!visited[i-1]的话则continue
            // if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
            //     continue;
            // }

            //如果当前下标已经加入了路径 或 本次选择的值和前一次相同，那么就再选择一个值;
            if (prev == nums[i] || used[i]) {
                continue;
            }
            prev = nums[i];
            used[i] = true;
            path.emplace_back(nums[i]);
            backtrack(nums, path, depth + 1, len, used);
            path.pop_back();
            used[i] = false;
        }
    }
private:
    std::vector<std::vector<int>> ans;
};

class Solution2 {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return {};
        }

        std::vector<std::vector<int>> ans;
        std::function<void(int)> backtrack = [&](int idx) {
            if (idx == nSize) {
                ans.emplace_back(nums);
                return;
            }
            
            std::unordered_set<int> st;
            for (int i = idx; i < nSize; ++i) {
                if (!st.count(nums[i])) {
                    st.insert(nums[i]);
                    std::swap(nums[idx], nums[i]);
                    backtrack(idx + 1);
                    std::swap(nums[idx], nums[i]);
                }
            }
        };

        backtrack(0);

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1,1,2};
    auto ans_vec = leetcode_cpp::Solution().permuteUnique(nums);
    for (const auto &ans : ans_vec) {
        for (const auto &i : ans) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}