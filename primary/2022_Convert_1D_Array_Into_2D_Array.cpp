#include <vector>
#include <iostream>
/*
@
project: Leetcode
time: 2022-01-01 19:25:02
author: edinw
@
*/


namespace leetcode_cpp {
class Solution{
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int> &original, int m, int n) {
        decltype(original.size()) nLength = original.size();
        if (m * n != nLength) {
            return ans;
        }
        for (auto it = original.begin(); it != original.end(); it += n) {
            ans.emplace_back(it, it + n);
        }
        return ans;
    }

private:
    std::vector<std::vector<int>> ans;
};
}

int main(int argc, char **argv) {
    std::vector<int> original {2};
    int m = 1, n = 1;
    auto ans = leetcode_cpp::Solution().construct2DArray(original, m, n);
    for (auto &nums : ans) {
        for (auto &num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}