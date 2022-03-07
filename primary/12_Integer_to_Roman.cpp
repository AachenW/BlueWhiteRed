#include <vector>
#include <iostream>

/*
@
LeetCode
time: 2022-02-25 20:34:41
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string intToRoman(int num) {
        std::vector<int> value{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        std::vector<std::string> symbol{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        std::string ans;
        for (int i = 0; i < value.size(); ++i) {
            while (num >= value[i]) {
                ans += symbol[i];
                num -= value[i];
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    int num = 1994;
    std::cout << leetcode_cpp::Solution().intToRoman(num) << std::endl;
    return 0;
}