#include <bits/stdc++.h>

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-04 23:26:37
author: edinw
@
*/

/*
**  由于题目要求删除和插入的时间复杂度为 O(1)，能够满足要求的只有哈希表，显然此处需要使用哈希表。
**
**  但是使用哈希表无法等概率返回其中的每个数值。若这些数值是保存在数组内，则可以轻松解决。但若只使用数组，那么删除和插入一个值时，都需遍历一遍数组找到数值对应的下标，则会使时间复杂度为 O(n)。
**
**  故可将哈希表和数组结合，数组内存数值实现 getRandom，哈希内存数值和下标的映射实现 insert 和 remove 的索引查找的时间复杂度为 O(1)，之后在数组内操作数值的插入和删除。

*/
namespace leetcode_cpp {
class RandomizedSet {
public:
    RandomizedSet() {
    
    }

    bool insert(int val) {
        if (hashMap.count(val)) {
            return false;
        }
        hashMap[val] = nums.size();
        nums.emplace_back(val);
        return true;
    }

    bool remove(int val) {
        if (!hashMap.count(val)) {
            return false;
        }

        int idx = hashMap[val]; // 通过HashMap获取该元素在数组中的下标idx
        hashMap[nums.back()] = idx; // 获取数组的最后一个元素的下标
        nums[idx] = nums.back();    // 将idx的值设为最后一个元素的值
        hashMap.erase(val); 
        nums.pop_back();    // 删除最后一个元素,即等同于删除该元素
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }


private:
    std::unordered_map<int, int> hashMap;
    std::vector<int> nums;
};
}
