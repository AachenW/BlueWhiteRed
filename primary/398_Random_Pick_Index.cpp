#include <vector>


// Note that for any i, the decision of whether or not to choose this ith number depends on the first term of the above mentioned expression, which is 1 / i 
// In general, if count represents the total number of numbers we have from which we need to chose a random number uniformly, we chose such a number with probability 1 / count. This is what we will be doing here.
namespace leetcode_cpp {
class Solution {
public:
    Solution(std::vector<int> &nums) {
        this->nums.swap(nums);
    }

    int pick(int target) {
        int n = nums.size();
        int count = 0;
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            // if nums[i] is equal to target, i is a potential candiate whick needs to be chosen uniformly at random
            if (nums[i] == target) {
                // increment the count of total candidates available to be chosen uniformly at random
                ++count;
                // we pick the current number with probability 1 / count (reservoir sampling)
                if (rand() % count) {
                    index = i;
                }
            }
        }

        return idx;
    
    }

private:
    std::vector<int> nums;
};

// 给定一个整数数组，设计一个方法，返回数组中最大值的下标。如果，最大值有重复出现，则按照相等的概率返回任意一个最大值的下标。附加条件：设计一个时间复杂度 O(n)，空间复杂度 O(1) 的算法。
class Solution {
public:
    Solution(std::vector<int> &nums) {
        this->nums.swap(nums);
    }

    int pick(int target) {
        int n = nums.size();
        int count = 0;
        int idx = 0;
        int maxNum = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                count = 0;
            }
            if (max == a[i]) {
                ++count;
                if (0 == rand() % count) {
                    idx = i;
                }
            }
        }

        return idx;
    }

private:
    std::vector<int> nums;
};
}

