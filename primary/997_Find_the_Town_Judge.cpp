#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>
#include <functional>

/*
@
projetc: leetcode
time: 2021-12-19 21:12:24
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    int findJudge(int n, std::vector<std::vector<int>> &trust) {
        std::vector<int> inDegrees(n + 1);
        std::vector<int> outDegrees(n + 1);
        for (auto &edge : trust) {
            int x = edge[0], y = edge[1];
            ++inDegrees[y];
            ++outDegrees[x];
        }
        
        for (int i = 1; i <= n; ++i) {
            if(inDegrees[i] == n - 1 && outDegrees[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
}

int maxNumber(std::vector<std::vector<int>> &trust) {
    int max = -1;
    for (auto &edge : trust) {
        for (auto &i : edge) {
            if (i > max) {
                max = i;
            }
        }
    }
    return max;
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> trust {{1, 2}};
    int n = maxNumber(trust);
    std::cout << leetcode_cpp::Solution().findJudge(n, trust) << std::endl;

    return 0; 
}