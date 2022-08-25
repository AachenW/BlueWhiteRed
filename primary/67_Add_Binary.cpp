#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-05 14:49:57 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int aLen = a.length(), bLen = b.length();
        int carry = 0;
        int idx1 = aLen - 1, idx2 = bLen - 1;
        std::string ans;

        while (idx1 >= 0 || idx2 >= 0 || carry) {
            int x = idx1 >= 0 ? a[idx1--] - '0' : 0;
            int y = idx2 >= 0 ? b[idx2--] - '0' : 0;
            int sum = x + y + carry;
            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        std::reverse(ans.begin(), ans.end());

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string a{"11"}, b{"1"};
    std::cout << leetcode_cpp::Solution().addBinary(a, b) << std::endl;
    return 0;
}