#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
/*
@
project: Leetcode
time: 2022-02-10 15:39:35
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> simplifiedFractions(int n) {
        std::vector<std::string> ans;
        for (int denominator = 2; denominator <= n; ++denominator) {
            for (int numerator = 1; numerator < denominator; ++numerator) {
                if (gcd(numerator, denominator) == 1) {
                    ans.emplace_back(std::to_string(numerator) + "/" + std::to_string(denominator));
                }
            }
        }

        return ans;
    }

private:
    int gcd(int a, int b) {
        if (a < b) {
            gcd(b, a);
        }
        if (m[a][b]) {
            return m[a][b];
        }
        int r = a % b;
        int ans = 1;
        if (0 == r) {
            ans = b;
        } else {
            ans = gcd(b, r);
        }
        m[a][b] = ans;
        return ans;
    }

private:
    std::unordered_map<int, std::unordered_map<int, int>> m;
};
}


int main(int argc, char **argv) {
    int n = 4;
    auto ans = leetcode_cpp::Solution().simplifiedFractions(n);
    for (const auto &str: ans) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}