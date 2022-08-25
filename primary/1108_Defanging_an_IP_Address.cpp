#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-06-21 09:08:56
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string defangIPaddr(std::string address) {
        std::string ans;
        for (const auto &ch: address) 
            if ('.' == ch) ans.append("[.]");
            else ans.push_back(ch);
        
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string address {"1.1.1.1"};
    std::cout << leetcode_cpp::Solution().defangIPaddr(address) << std::endl;

    return 0;

}