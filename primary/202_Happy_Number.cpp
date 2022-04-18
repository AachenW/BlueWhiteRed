#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-02-14 23:54:27
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isHappy(int n) {
        auto getNext = [] (int n) -> int {
            int sum = 0;
            while (n > 0) {
                int d = n % 10;
                n /= 10;
                sum += d * d;
            }
            return sum;
        };

        int slow = n;
        int fast = n;
        while (1 != fast && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return 1 == fast;
    }
};    
}