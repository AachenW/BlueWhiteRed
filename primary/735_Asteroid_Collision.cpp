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
            // 栈不为空，栈顶小行星向右飞行，当前小行星向左飞行且栈顶小行星较小的情况，栈顶小行星爆炸
            while (!dq.empty() && dq.back() > 0 && dq.back() < -asteroid) {
                dq.pop_back();
            }

            // 栈不为空，当前小行星向左飞行，且俩行星大小相同的情况，同时爆炸
            if (!dq.empty() && asteroid < 0 && dq.back() == -asteroid) {
                dq.pop_back();
                
            }
            // 1、若当前小行星向右飞行，不用管栈顶小行星的飞行方向，它肯定不会与栈顶小行星相撞；
            // 2、栈为空时，当前小行星入栈；
            // 3、若栈顶小行星向左飞行，不用管当前小行星的飞行方向，它肯定不会与栈顶小行星相撞； 
            else if (asteroid > 0 || dq.empty() || dq.back() < 0) {
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
