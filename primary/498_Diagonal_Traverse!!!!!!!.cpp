#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<int>> vec(m + n, std::vector<int>());
        std::vector<int> v;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vec[i + j].emplace_back(matrix[i][j]);
            }
        }

        for (int i = 0; i < vec.size(); ++i) {
            if (0 == i % 2) {
                std::reverse(vec[i].begin(), vec[i].end());
            }

            for (int j = 0; j < vec[i].size(); ++j) {
                v.emplace_back(vec[i][j]);
            }
        }

        return v;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> matrix {{1,2,3},{4,5,6},{7,8,9}};

    auto ans = leetcode_cpp::Solution().findDiagonalOrder(matrix);

    for (auto &&output: ans) {
        std::cout << output << ",";
    }
    std::cout << std::endl;

    return 0;
}