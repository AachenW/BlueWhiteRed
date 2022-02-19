#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <functional>
/*
@
projetc: leetcode
time: 2022-02-08 20:12:51
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public: 
    std::vector<int> gridIllumination(int n, std::vector<std::vector<int>> &lamps, std::vector<std::vector<int>> &queries) {
        std::unordered_map<int, int> row, col, diagonal, antiDiagonal;
        auto hash_p = [](const std::pair<int, int> &p) -> size_t {
            static std::hash<long long> hash_ll;
            return hash_ll(p.first + (static_cast<long long>(p.second) << 32));
        };

        std::unordered_set<std::pair<int, int>, decltype(hash_p)> points(0, hash_p);

        for (const auto &lamp: lamps) {
            if (points.count({lamp[0], lamp[1]}) > 0) {
                continue;
            }
            points.insert({lamp[0], lamp[1]});
            ++row[lamp[0]];
            ++col[lamp[1]];
            ++diagonal[lamp[0] - lamp[1]];
            ++antiDiagonal[lamp[0] + lamp[1]];
        }

        int qSize = queries.size();
        std::vector<int> ret(qSize);
        for (int i = 0; i < qSize; ++i) {
            int r = queries[i][0], c = queries[i][1];
            if (row.count(r) > 0 && row[r] > 0) {
                ret[i] = 1;
            } else if (col.count(c) > 0 && col[c] > 0) {
                ret[i] = 1;
            } else if (diagonal.count(r - c) > 0 && diagonal[r - c] > 0) {
                ret[i] = 1;
            } else if (antiDiagonal.count(r + c) > 0 && antiDiagonal[r + c] > 0) {
                ret[i] = 1;
            }

            for (int x = r - 1; x <= r + 1; ++x) {
                for (int y = c - 1; y <= c + 1; ++y) {
                    if (x < 0 || y < 0 || x >= n || y >= n) {
                        continue;
                    }
                    auto p = points.find({x, y});
                    if (p != points.end()) {
                        points.erase(p);
                        --row[x];
                        --col[y];
                        --diagonal[x - y];
                        --antiDiagonal[x + y];
                    }
                }
            }
        }
        return ret;
    }
};
}

int main(int argc, char **argv) {
    int n = 5;
    std::vector<std::vector<int>> lamps{{0, 0}, {0, 4}};
    std::vector<std::vector<int>> queries{{0, 4}, {0, 1}, {1, 4}};
    auto ans = leetcode_cpp::Solution().gridIllumination(n, lamps, queries);
    for (const auto num: ans) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}