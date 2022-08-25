#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-20 13:26:48 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> numsSameConsecDiff(int n, int k) {
        std::vector<int> ans;

        std::function<void(std::string)> dfs = [&] (std::string s) {
            if (s.length() >= n) {
                ans.emplace_back(std::stoi(s));
                return;
            }

            int num = s.back() - '0';
            if (num + k < 10) {
                s.push_back('0' + num + k);
                dfs(s);
                s.pop_back();
            }
            if (num - k >= 0 && k != 0) {
                s.push_back('0' + num - k);
                dfs(s);
                s.pop_back();
            }
        };

        for (int i = 1; i < 10; ++i) {
            if (i + k > 9 && i - k < 0) {
                continue;
            }
            dfs(std::to_string(i));
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    int n = 3, k = 7;
    
    auto ans = leetcode_cpp::Solution().numsSameConsecDiff(n, k);
    for (int output: ans) {
        std::cout << output << ",";
    }
    std::cout << '\n';

    return 0;

}
