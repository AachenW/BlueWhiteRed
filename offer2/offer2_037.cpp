#include <iostream>
#include <vector>
#include <deque>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-09 21:57:04
author: edinw
@
*/

/*
注意：本题与主站 735 题相同： https://leetcode-cn.com/problems/asteroid-collision/

给定一个整数数组 asteroids，表示在同一行的小行星。
对于数组中的每一个元素，其绝对值表示小行星的大小，正负表示小行星的移动方向（正表示向右移动，负表示向左移动）。每一颗小行星以相同的速度移动。
找出碰撞后剩下的所有小行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int> &asteroids) {
        int aSize = asteroids.size();
        if (aSize < 2) {
            return asteroids;
        }        
        std::vector<int> dq;                //我们用数组模拟栈
        for (const auto &asteroid : asteroids) {
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
            else if (asteroid > 0 || dq.empty() || dq.back() < 0){
                dq.push_back(asteroid);
            }
        }

        return dq;

    }
};
}

int main(int argc, char **argv) {
    std::vector<int> asteroids {10, -10};
    auto ans = leetcode_cpp::Solution().asteroidCollision(asteroids);
    for (const auto &output : asteroids) {
        std::cout << output << " ";
    }
    std::cout << std::endl;
    return 0;
}