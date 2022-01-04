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
time: 2021-12-10 19:26:50
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string shortestCompletingWord(std::string licensePlate, std::vector<std::string>& words) {
        std::array<int, 26> cnt {};
        for (char ch : licensePlate) {
            if (isalpha(ch)) {  // 统计licensePlate中各个字符出现的次数
                ++cnt[tolower(ch) - 'a'];
            }
        }

        int idx= -1;
        int wLength = words.size();
        for (int i = 0; i < wLength; ++i) {
            std::array<int, 26> c{};
            for (char ch : words[i]) {  // 统计当前word中各个字符出现的次数
                ++c[ch - 'a'];
            }
            bool ok = true;
            for (int j = 0; j < 26; ++j) {
                if (c[j] < cnt[j]) {    // 若当前字符串的对应字符个数少于补全词对应字符个数时，不满足补全词条件
                    ok = false;
                    break;
                }
            }
            // 当前字符串满足补全词条件，且比之前保存的补全词还要短，则更新最短补全词
            if (ok && (idx < 0 || words[i].length() < words[idx].length())) {
                idx = i;
            }
        }
        return words[idx];
    }
};
}

int main(int argc, char** argv) {
    std::string licensePlate = "1s3 PSt";
    std::vector<std::string> words{"step","steps","stripe","stepple"};
    std::cout << leetcode_cpp::Solution().shortestCompletingWord(licensePlate, words) << std::endl;
}