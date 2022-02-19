#include <vector>
#include <string>
#include "limits.h"
#include <iostream>

/*
@
project: Leetcode
time: 2022-01-09 19:31:40
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    char slowestKey(std::vector<int> &releaseTimes, std::string keysPressed) {
        int kSize = keysPressed.size();
        if (0 == kSize) {
            return (char)0;
        }
        char curSlowestKey;
        int curSlowestTime = INT_MIN, initTime = 0;
        for (int i = 0; i < kSize; ++i) {
            if (releaseTimes[i] - initTime > curSlowestTime) {
                curSlowestTime = releaseTimes[i] - initTime;
                curSlowestKey = keysPressed[i];
                
            } else if (releaseTimes[i] - initTime == curSlowestTime) {
                if (keysPressed[i] > curSlowestKey) {
                    curSlowestKey = keysPressed[i];
                }
            } 
            initTime = releaseTimes[i];
        }
        return curSlowestKey;
    }
};
}

int main (int argc, char **argv) {
    std::vector<int> releaseTimes = {12,23,36,46,62};
    std::string keysPressed = "spuda";
    std::cout << leetcode_cpp::Solution().slowestKey(releaseTimes, keysPressed) << std::endl;
    return 0;
}