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

/*
@
time: 2021-12-06 21:31:25
author: edinw
@
*/




namespace leetcode_cpp {
class Solution {
public:
    int lastRemaining (int n, int m) {
        int pos = 0;
        for (int i = 2; i <= n; ++i) {
            pos = (pos + m) % i;    // 每次循环右移
        }
        return pos;
    }
};
}

int main(int argc, char** argv) {
    
    int n = 10, m = 17;
    std::cout << leetcode_cpp::Solution().lastRemaining(n, m) << std::endl;
}