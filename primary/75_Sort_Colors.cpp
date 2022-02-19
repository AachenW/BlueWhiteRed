#include <iostream>
#include <vector>

/*
@
projetc: leetcode
time: 2022-02-08 23:11:06
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    void sortColors(std::vector<int> &nums) {
        int nLen = nums.size();
        int ptr = 0;

        // 第一次遍历中，将数组中所有的 0 交换到数组的头部
        for (int i = 0; i < nLen; ++i) {
            if (0 == nums[i]) {
                std::swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
        // 在第二次遍历中，我们将数组中所有的 1 交换到头部的 0 之后
        for (int i = ptr; i < nLen; ++i) {
            if (1 == nums[i]) {
                std::swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
    }
};

class Solution2 {
public:
    void sortColors(std::vector<int> &nums) {
        int nLen = nums.size();
        int p0 = 0, p1 = 0;         // 用指针 p0 来交换0, p1来交换1
        for (int i = 0; i < nLen; ++i) {
            // 如果 p0 < p1, 那么我们需要再将 nums[i] 与 nums[p1] 进行交换，其中 i 是当前遍历到的位置，在进行了第一次交换后，nums[i] 的值为 1，我们需要将这个 1 放到「头部」的末端
            if (0 == nums[i]) {         
                std::swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    std::swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            } else if (1 == nums[i]) {  // 如果找到了1, 那么将其与 nums[p1] 进行交换，并将 p1向后移动一个位置
                std::swap(nums[i], nums[p1]);
                ++p1;
            }
        }
    }
};

class Solution3 {
public:
    void sortColors(std::vector<int> &nums) {
        int nLen = nums.size();
        int p0 = 0, p2 = nLen - 1;
        for (int i = 0; i <= p2; ++i) {
            // 当我们找到 2 时，需要不断地将其与 nums[p2] 进行交换，直到新的 nums[i] 不为 2
            while (i <= p2 && 2 == nums[i]) {
                std::swap(nums[i], nums[p2--]);
            }
            // 如果找到了 0，那么与前面两种方法类似，将其与 nums[p0]进行交换，并将 p0 向后移动一个位置
            if (0 == nums[i]) {
                std::swap(nums[i], nums[p0++]);
            }
        }
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {2, 0, 1};
    leetcode_cpp::Solution3().sortColors(nums);
    for (const auto &num: nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}