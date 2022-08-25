#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-11 13:14:07 
author: edinw
@
*/

namespace leetcode_cpp {
class RandomizedCollection() {
public:
    RandomizedCollection() {
    
    }

    bool insert(int val) {
        nums.emplace_back(val);
        idx[val].emplace_back(nums.size() - 1);
        return 1 == idx[val].size();
    }
    
    bool remove(int val) {
        if (idx.find(val) == idx.end()) return false;

        int i = *(idx[val].begin());
        nums[i] = nums.back();
        idx[val].erase(i);
        idx[nums[i]].erase(nums.size() - 1);
        // 如果删除元素恰好就是最后一个元素，避免添加错误元素
        if (i < nums.size() - 1) idx[nums[i]].insert(i);
        if (!idx[val].size()) idx.erase(val);
        nums.pop_back();
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }

public:
    std::unordered_map<int, std::unordered_set<int>> idx;
    std::vector<int> nums;
};
}

