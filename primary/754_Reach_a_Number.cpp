#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-13 18:54:13
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int reachNumber(int target) {
        target = target < 0 ? -target : target;
        int ans = 0, start = 0, step = 1;
        
        while (start < target) {
           start += step;
           ++step;
           ++ans;
        }
            
        if (start == target) {
            return ans;
        } else {
            int diff = start - target;
            while (diff & 1) {
                start += step;
                ++step;
                ++ans;
                diff = start - target;
            }
            return ans;
        }
    }
};
}

int main(int argc, char **argv) {
    int target = -3;

    std::cout << leetcode_cpp::Solution().reachNumber(target) << '\n';

    return 0;

}
