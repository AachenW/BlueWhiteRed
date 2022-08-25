#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-06-08 10:28:27 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isBoomerang(std::vector<std::vector<int>> &points) {
        std::vector<int> v1 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        std::vector<int> v2 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};

        return v1[0] * v2[1] - v1[1] * v2[0] != 0;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> points{{1, 1}, {2, 3}, {3, 2}};
    std::cout << std::boolalpha << leetcode_cpp::Solution().isBoomerang(points) << std::endl;
    return 0;
}
