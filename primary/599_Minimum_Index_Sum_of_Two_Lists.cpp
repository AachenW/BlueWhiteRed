#include <vector>
#include <iostream>
#include "limits.h"
#include <algorithm>

/*
@
project: leetcode
time: 2022-03-15 10:43:29
author: edinw
@
*/
namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
        std::unordered_map<std::string, int> index1, index2;
        int lSize1 = list1.size(), lSize2 = list2.size();

        for (int i = 0; i < lSize1; ++i) {
            if (!index1.count(list1[i])) {
                index1[list1[i]] = i;
            }
        }

        int minIdxSum = INT_MAX;
        std::vector<std::string> ans;
        for (int i = 0; i < lSize2; ++i) {
            if (index1.count(list2[i])) {
                int idxSum = index1[list2[i]] + i;
                if (idxSum > minIdxSum) {
                    continue;
                } else if (idxSum < minIdxSum) {
                    ans.clear();
                    ans.emplace_back(list2[i]);
                    minIdxSum = idxSum;
                } else {
                    ans.emplace_back(list2[i]);
                }
            }
        }

        return ans;
    }
};
}


int main(int argc, char **argv) {
    std::vector<std::string> list1{"Shogun","Tapioca Express","Burger King","KFC"};
    std::vector<std::string> list2{"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};

    auto ans = leetcode_cpp::Solution().findRestaurant(list1, list2);
    for (auto &&str: ans) {
        std::cout << str << std::endl;
    }

    return 0;
}