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
    std::string truncateSentence(std::string s, int k) {
        int nLength = s.size();
        int end = 0, count = 0;
        for (int i = 0; i <= nLength; ++i) {
            if (i == nLength || s[i] == ' ') {
                ++count;    // 每隔一个空格，单词计数+1
                if (count == k) {   // 若到达目的个数截断点，则返回此处的index
                    end = i;
                    break;
                }
            }
        }
        return s.substr(0, end);  // 截断字符串
    }
};
}

int main(int argc, char** argv) {
    std::string s = "chopper is not a tanuki";
    int target = 5;
    std::cout << leetcode_cpp::Solution().truncateSentence(s, target) << std::endl;
}