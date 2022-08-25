#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-03 11:09:52 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> reorderLogFiles(std::vector<std::string> &logs) {
        auto cmp = [&] (const std::string &log1, const std::string &log2) {
            int pos1 = log1.find_first_of(" ");
            int pos2 = log2.find_first_of(" ");
            bool isDigit1 = isdigit(log1[pos1 + 1]);
            bool isDigit2 = isdigit(log2[pos2 + 1]);

            if (isDigit1 && isDigit2) {
                return false;
            }
            if (!isDigit1 && !isDigit2) {
                std::string s1 = log1.substr(pos1);
                std::string s2 = log2.substr(pos2);
                if (s1 != s2) {
                    return s1 < s2;
                }
                return log1 < log2;
            }
            return isDigit1 ? false : true;
        };

        std::stable_sort(logs.begin(), logs.end(), cmp);

        return logs;
    }

};
}


int main (int argc, char **argv) {
    std::vector<std::string> logs {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};

    auto ans = leetcode_cpp::Solution().reorderLogFiles(logs);
    for (auto log: ans) {
        std::cout << log << '\n';
    }
    std::cout << std::endl;

    return 0;

}
