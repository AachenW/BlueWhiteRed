#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-19 17:31:11 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string ans;

        while (columnNumber > 0) {
            --columnNumber;
            ans += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
}

int main(int argc, char **argv) {
    int columnNumber = 701;

    std::cout << leetcode_cpp::Solution().convertToTitle(columnNumber) << '\n';

    return 0;
}

