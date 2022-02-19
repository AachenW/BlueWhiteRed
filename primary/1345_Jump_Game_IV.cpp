#include <vector>
#include <iostream>
#include <map>
/*
@
project: Leetcode
time: 2022-01-21 21:28:32
author: edinw
@
*/


namespace leetcode_cpp {
class Solution {
public:
    int minJumps(std::vector<int> &arr) {
        int nLength = arr.size();
        if (2 > nLength) {
            return 0;
        }

        std::map<int, int> hashMap;
        for (int i = 0; i < nLength; ++i) {
            hashMap.insert(std::make_pair(arr.at(i), i));
        }

        auto dp = std::vector<int>(nLength);
        
        for (int i = 1; i < nLength; ++i) {
            if (hashMap.count(arr.at(i))) {
                auto pair = hashMap.equal_range(arr.at(i));
                if (pair.first != hashMap.end()){
                    int minIndex = i;
                    for(auto it = pair.first; it != pair.second; ++it) {
                        
                        if (i != it->second) {
                            minIndex = std::min(minIndex, it->second);
                        }
                    }
                    dp[i] = dp[minIndex] + 1;
                }
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }

        return dp[nLength - 1];
    }
};
}


int main(int argc, char **argv) {
    std::vector<int> arr {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    std::cout << leetcode_cpp::Solution().minJumps(arr) << std::endl;
    return 0;
}