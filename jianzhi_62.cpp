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

namespace leetcode_cpp {
class Solution {
public:
    // 约瑟夫环
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
    std::cout << leetcode_cpp::Solution().lastRemaining(5, 3);
}

