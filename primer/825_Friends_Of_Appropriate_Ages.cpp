#include <vector>
#include <iostream>
#include <algorithm>
/*
@
projetc: leetcode
time: 2021-12-27 22:28:49
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    int numFriendRequests(std::vector<int> &ages) {
        typedef decltype(ages.size()) sz;
        sz n = ages.size();
        std::sort(ages.begin(), ages.end());
        sz left = 0, right = 0, ans = 0;
        for (int &age : ages) {
            if (age < 15) {
                continue;
            }
            while (ages[left] <= 0.5 * age + 7) {
                ++left;
            }
            while (right + 1 < n && ages[right + 1] <= age) {
                ++right;
            }
            ans += right - left;
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> ages {20,30,100,110,12};
    std::cout << leetcode_cpp::Solution().numFriendRequests(ages) << std::endl;
    return 0;
}