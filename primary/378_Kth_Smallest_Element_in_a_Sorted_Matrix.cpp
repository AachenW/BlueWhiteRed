#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-03 11:32:55 
author: edinw
@
*/

namespace leetcode_cpp {
class Point {
public:
    int val, x, y;
    Point(int val, int x, int y) : val(val), x(x), y(y) {}
    bool operator> (const Point& a) const { return this->val > a.val; };
};

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>> &matrix, int k) {
        if (0 == matrix.size() || 0 == matrix[0].size()) {
            return -1;
        }
        
        int rows = matrix.size(), cols = matrix[0].size();

        std::priority_queue<Point, std::vector<Point>, std::greater<Point>> pq;

        for (int i = 0; i < rows; ++i) {
            pq.emplace(matrix[i][0], i, 0);
        }
        
        for (int i = 1; i < k; ++i) {
            Point now = pq.top(); pq.pop();
            if (now.y != cols - 1) {
                pq.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
            }
        }
        
        return pq.top().val;
    }
};

class Solution2 {
public:
    int kthSmallest(std::vector<std::vector<int>> &matrix, int k) {
        if (0 == matrix.size() || 0 == matrix[0].size()) {
            return -1;
        }
        
        int rows = matrix.size(), cols = matrix[0].size();
        int left = matrix[0][0], right = matrix[rows - 1][cols - 1];

        auto check = [&] (int mid) -> int {
            int i = rows - 1, j = 0;
            int num = 0;
            while (i >= 0 && j < cols) {
                if (matrix[i][j] <= mid) {
                    num += i + 1;
                    ++j;
                } else {
                    --i;
                }
            }
            return num >= k;
        };

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
}


int main(int argc, char **argv) {
   std::vector<std::vector<int>> matrix{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
   int k = 8;

   std::cout << leetcode_cpp::Solution2().kthSmallest(matrix, k) << '\n';

   return 0;
}
