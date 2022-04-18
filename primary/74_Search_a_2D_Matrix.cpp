#include <iostream>
#include <vector>

/*
@
projetc: leetcode
time: 2022-03-23 16:33:46
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (0 == matrix.size() || 0 == matrix[0].size()) {
            return false;
        }

        int rows = matrix.size(), cols = matrix[0].size();
        int lo = 0, hi = rows * cols - 1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            int num = matrix[mid / cols][mid % cols];
            if (num == target) {
                return true;
            } else if (num < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return false;
    }
};

class Solution2 {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (0 == matrix.size() || 0 == matrix[0].size()) {
            return false;
        }

        int rows = matrix.size(), cols = matrix[0].size();
        int x = 0, y = cols - 1;

        while (x < rows && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                ++x;
            } else {
                --y;
            }
        }

        return false;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    
    std::cout << std::boolalpha << leetcode_cpp::Solution().searchMatrix(matrix, target) << std::endl;

    return 0;
}