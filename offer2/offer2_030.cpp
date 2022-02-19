#include <vector>
#include <map>
#include <utility>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-05 19:55:24
author: edinw
@
*/

/*
注意：本题与主站 380 题相同：https://leetcode-cn.com/problems/insert-delete-getrandom-o1/

设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构：

    insert(val)：当元素 val 不存在时返回 true ，并向集合中插入该项，否则返回 false 。
    remove(val)：当元素 val 存在时返回 true ，并从集合中移除该项，否则返回 false 。
    getRandom：随机返回现有集合中的一项。每个元素应该有 相同的概率 被返回。
 
*/


namespace leetcode_cpp {
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hashMap.count(val)) {
            return false;
        }
        nums.emplace_back(val);
        hashMap.insert(std::make_pair(val, nums.size()));
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!hashMap.count(val)) {
            return false;
        }
        hashMap[nums.back()] = hashMap[val];
        hashMap.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    std::vector<int> nums;
    std::map<int, int> hashMap;
};
}

int main(int argc, char **argv) {
    
}