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
time: 2021-12-12 20:34:35
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string toLowerCase(std::string s) {
        int sLength = s.size();
        for (int i = 0; i < sLength; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 'a' - 'A';
            }
        }
        return s;
    }
};
}

int main(int argc, char** argv) {
    std::string s1 = "Hello", s2 = "here", s3 = "LOVELY";
    std::cout << leetcode_cpp::Solution().toLowerCase(s1) << std::endl;
    std::cout << leetcode_cpp::Solution().toLowerCase(s2) << std::endl;
    std::cout << leetcode_cpp::Solution().toLowerCase(s3) << std::endl;
    
}