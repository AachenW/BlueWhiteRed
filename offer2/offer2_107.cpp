#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-14 22:18:55
author: edinw
@
*/

/*
注意：本题与主站 542 题相同：https://leetcode-cn.com/problems/01-matrix/

给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。
*/

namespace leetcode_cpp {
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size(), n = matrix.at(0).size();
        std::vector<std::vector<int>> dists (m, std::vector<int>(n));
        std::deque<std::pair<int, int>> queue;
        // 将所有的0添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix.at(i).at(j) == 0) {
                    queue.emplace_back(std::make_pair(i, j));
                    dists.at(i).at(j) = 0;          // 因为该距离最近的 0 的距离自然是 0
                } else {
                    dists.at(i).at(j) = INT_MAX;    // 表示mat[i][j]=1，且未搜索
                }
            }
        }

        // BFS
        while (!queue.empty()) {
            auto element = queue.front();
            queue.pop_front();
            int dist = dists.at(element.first).at(element.second);  // 取该格子距离最近的 0 的距离 dist 为 dists[i][j]
            // 设该格子往上下左右方向到达的格子为[r, c].若格子[r, c]之前从未被搜索过，那么dists[i][j]为INT_MAX，则dist + 1 < dists[i][j]必成立，并且该格子距离0的最近距离为 dist + 1，即更新 dists[i][j] 为 dist + 1。
            for (int index = 0; index < 4; ++index) {
                int next_x = element.first + dirs[index][0];
                int next_y = element.second + dirs[index][1];
                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n) {
                    if (dist + 1 < dists.at(next_x).at(next_y)) {
                        dists.at(next_x).at(next_y) = dists.at(element.first).at(element.second) + 1;
                        queue.emplace_back(std::make_pair(next_x, next_y));
                    }
                }
            }
        }

        return dists;

    }
};


class Solution2 {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size(), n = matrix.at(0).size();
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == matrix.at(i).at(j)) {
                    dist.at(i).at(j) = 0;
                }
            }
        }

        // 只有 水平向左移动 和 竖直向上移动，注意动态规划的计算顺序
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0) {
                    dist.at(i).at(j) = std::min(dist.at(i).at(j), dist.at(i - 1).at(j) + 1);
                }
                if (j - 1 >= 0) {
                    dist.at(i).at(j) = std::min(dist.at(i).at(j), dist.at(i).at(j - 1) + 1);
                }
            }
        }

        // 只有 水平向左移动 和 竖直向下移动，注意动态规划的计算顺序
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < m) {
                    dist[i][j] = std::min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j - 1 >= 0) {
                    dist[i][j] = std::min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        // 只有 水平向右移动 和 竖直向上移动，注意动态规划的计算顺序
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i - 1 >= 0) {
                    dist[i][j] = std::min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j + 1 < n) {
                    dist[i][j] = std::min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        // 只有 水平向右移动 和 竖直向下移动，注意动态规划的计算顺序
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i + 1 < m) {
                    dist[i][j] = std::min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j + 1 < n) {
                    dist[i][j] = std::min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        return dist;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size(), n = matrix.at(0).size();
        // 初始化动态规划的数组，所有的距离值都设置为一个很大的数
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX / 2));
        // 如果 (i, j) 的元素为 0，那么距离为 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == matrix.at(i).at(j)) {
                    dist.at(i).at(j) = 0;
                }
            }
        }

        // 只有 水平向左移动 和 竖直向上移动，注意动态规划的计算顺序
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0) {
                    dist.at(i).at(j) = std::min(dist.at(i).at(j), dist.at(i - 1).at(j) + 1);
                }
                if (j - 1 >= 0) {
                    dist.at(i).at(j) = std::min(dist.at(i).at(j), dist.at(i).at(j - 1) + 1);
                }
            }
        }

        // 只有 水平向右移动 和 竖直向下移动，注意动态规划的计算顺序
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i + 1 < m) {
                    dist[i][j] = std::min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j + 1 < n) {
                    dist[i][j] = std::min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }

        return dist;
    }
};
}

constexpr int leetcode_cpp::Solution::dirs[4][2];

int main(int argc, char **argv) {
    std::vector<std::vector<int>> mat {{0,0,0},{0,1,0},{1, 1, 1}};
    auto ans = leetcode_cpp::Solution().updateMatrix(mat);
    for (const auto &nums: ans) {
        for (const auto &num: nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}