/*
@
time: 2021-12-07 23:04:25
author: edinw
@
*/

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
class Solution{
public:
    int add(int a, int b) {
        int sum, carry;
        do {
            sum = a ^ b;
            carry = (unsigned int)(a & b) << 1;
            a = sum;
            b = carry;
        }while(b != 0);
        return a;
    }
};
}

int main(int argc, char** argv) {
    std::cout << leetcode_cpp::Solution().add(1, 1) << std::endl;
}