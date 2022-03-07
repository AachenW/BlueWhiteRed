#include <unordered_set>
#include <iostream>
#include <vector>


namespace leetcode_cpp {
class Solution {
public:
    int longestConsecutive(std::vector<int> &nums) {
        std::unordered_set<int> seen;

        for (auto &&num: nums) {
            seen.insert(num);
        }

        int maxLength = 0;
        for (auto &&key: nums) {
            if (!seen.count(key - 1)) {
                int curNum = key;
                int curSteak = 1;

                while (seen.count(curNum + 1)) {
                    ++curNum;
                    ++curSteak;
                }

                maxLength = std::max(maxLength, curSteak);
            }
        }

        return maxLength;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {0,3,7,2,5,8,4,6,0,1};

    std::cout << leetcode_cpp::Solution().longestConsecutive(nums) << std::endl;

    return 0;
}