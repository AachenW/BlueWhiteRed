#include <vector>
#include <iostream>

/*
@
project: leetcode
time: 2022-03-05 13:07:16
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int> &asteroids) {
        int aSize = asteroids.size();
        if (aSize < 2) {
            return asteroids;
        }
        std::vector<int> dq;
        for (auto &&asteroid: asteroids) {
            while (!dq.empty() && dq.back() > 0 && dq.back() < -asteroid) {
                dq.pop_back();
            }

            if (!dq.empty() && asteroid < 0 && dq.back() == -asteroid) {
                dq.pop_back();
            } else if (asteroid > 0 || dq.empty() || dq.back() < 0) {
                dq.emplace_back(asteroid);
            }
        }

        return dq;
    }
};

}

int main(int argc, char **argv) {
    std::vector<int> asteroids {5, 10, -5};

    auto ans = leetcode_cpp::Solution().asteroidCollision(asteroids);

    for (auto &&output: ans) {
        std::cout << output << ",";
    }
    std::cout << std::endl;

    return 0;

}
