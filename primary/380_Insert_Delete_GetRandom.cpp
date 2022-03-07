/*
@
LeetCode 剑指offerⅡ
time: 2022-03-04 23:26:37
author: edinw
@
*/


namespace leetcode_cpp {
class RandomizedSet {
public:
    RandomizedSet {
    
    }

    bool insert(int val) {
        if (hashMap.count(val)) {
            return false;
        }
        hashMap.insert(std::make_pair(val, nums.size()));
        nums.emplace_back(val);
        return true;
    }

    bool remove(int val) {
        if (!hashMap.count(val)) {
            return false;
        }
        int idx = hashMap[val];
        hashMap[nums.back()] = idx;
        nums[idx] = nums.back();
        hashMap.erase(val);
        nums.pop_back();
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }


private:
    unordered_map<int, int> hashMap;
    std::vector<int> nums;
};

}
