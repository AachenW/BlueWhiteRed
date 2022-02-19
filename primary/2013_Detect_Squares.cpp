#include <vector>
#include <unordered_map>
#include <iostream>

/*
@
project: Leetcode
time: 2022-01-26 19:56:31
author: edinw
@
*/

namespace leetcode_cpp {
class DetectSquares {
    std::unordered_map<int, std::unordered_map<int, int>> cnt;
public:
    DetectSquares() {

    }

    void add(std::vector<int> point) {
        int x = point[0], y = point[1];
        ++cnt[y][x];
    }

    int count(std::vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        if (!cnt.count(y)) {
            return 0;
        }
        std::unordered_map<int, int> &yCnt = cnt[y];
        for (auto &[col, colCnt]: cnt) {
            if (col != y) {
                int d = col - y;
                res += (colCnt.count(x) ? colCnt[x] : 0) * (yCnt.count(x + d) ? yCnt[x + d] : 0) *
                       (colCnt.count(x + d) ? colCnt[x + d] : 0);
                res += (colCnt.count(x) ? colCnt[x] : 0) * (yCnt.count(x - d) ? yCnt[x - d] : 0) *
                       (colCnt.count(x - d) ? colCnt[x - d] : 0);
            }
        }
        return res;
    }
};
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

int main(int argc, char **argv) {
    auto pSquares = new leetcode_cpp::DetectSquares();

    pSquares->add({3, 10});
    pSquares->add({11, 2});
    pSquares->add({3, 2});
    std::cout << pSquares->count({11, 10}) << std::endl;;
    std::cout << pSquares->count({14,8}) << std::endl;
    pSquares->add({11, 2});
    std::cout << pSquares->count({11, 10}) << std::endl;

    delete pSquares;
    return 0;
}