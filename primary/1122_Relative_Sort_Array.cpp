#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-25 21:27:34
author: edinw
@
*/

/*
**  注意：本题与主站 1122 题相同：https://leetcode-cn.com/problems/relative-sort-array/ 
** 
**  Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
**  Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int> &arr1, std::vector<int> &arr2) {
        std::unordered_map<int, int> orderMap;
        for (int i = 0; i < arr2.size(); ++i) {
            orderMap[arr2[i]] = i;
        }

        std::sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            if (orderMap.count(x)) {
                return orderMap.count(y) ? orderMap[x] < orderMap[y] : true;
            } else {
                return orderMap.count(y) ? false : x < y;
            }
        });

        return arr1;
    }
};

class Solution2 {
public:
    std::vector<int> relativeSortArray(std::vector<int> &arr1, std::vector<int> &arr2) {
        auto upper = *std::max_element(arr1.begin(), arr1.end());
        std::vector<int> frequence(upper + 1);
        for (const auto &num: arr1) {
            ++frequence[num];
        }
        
        std::vector<int> ans;
        for (const auto &num: arr2) {
            for (int i = 0; i < frequence[num]; ++i) {
                ans.emplace_back(num);
            }
            frequence[num] = 0;
        }

        for (int i = 0; i <= upper; ++i) {
            for (int j = 0; j < frequence[i]; ++j) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> arr1{2,3,1,3,2,4,6,7,9,2,19};
    std::vector<int> arr2{2, 1, 4, 3, 9, 6};
    auto ans = leetcode_cpp::Solution2().relativeSortArray(arr1, arr2);
    for (const auto &output: ans) {
        std::cout << output << " ";
    }
    std::cout << std::endl;
    return 0;
}