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
time: 2021-12-08 21:42:46
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    std::vector<int> constructArr(std::vector<int>& a) {
        int aLength = a.size();
        if (aLength == 0) {
            return {};
        }
        std::vector<int> b(aLength, 1);
        b[0] = 1;
        int temp = 1;
        for (int i = 1; i < aLength; ++i) {
            b[i] = b[i - 1] * a[i - 1];
        }
        for (int i = aLength - 2; i >= 0; --i) {
            temp *= a[i + 1];
            b[i] *= temp;
        }
        return b;
    }
};
}

int main(int argc, char** argv) {
    std::vector<int> nums = {1,2,3,4,5};
    std::vector<int> ans = leetcode_cpp::Solution().constructArr(nums);
    for (int output: ans) {
        std::cout << output << "\t";
    } 
}