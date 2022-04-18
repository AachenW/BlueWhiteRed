#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-17 22:08:48 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> sortArray(std::vector<int> &nums) {
        // quickSort(nums);
        // mergeSort(nums);
        heapSort(nums);
        return nums;
    }

private:
    void quickSort(std::vector<int> &nums) {
        int nSize = nums.size();
        quickSortCore(nums, 0, nums.size() - 1);
    }

    void quickSortCore(std::vector<int> &nums, int lo, int hi) {
        if (lo >= hi) {
            return;
        }

        int pivot = (rand() % (hi - lo + 1)) + lo;
        int picked = nums[pivot];
        int left = lo, right = hi;
        
        std::swap(nums[left], nums[pivot]);
        while (left < right) {
            while (left < right && nums[right] >= picked) --right;
            while (left < right && nums[left] <= picked) ++left;
            std::swap(nums[left], nums[right]);
        }
        std::swap(nums[left], nums[lo]);

        quickSortCore(nums, lo, left - 1);
        quickSortCore(nums, left + 1, hi);
    }

    void mergeSort(std::vector<int> &nums) {
        std::vector<int> copyNum(nums);
        mergeSortCore(nums, copyNum, 0, nums.size() - 1);
    }

    void mergeSortCore(std::vector<int> &nums, std::vector<int> &copyNum, int lo, int hi) {
        if (lo >= hi) {
            return;
        }

        int mid = lo +((hi - lo) >> 1);
        int start1 = lo, end1 = mid, start2 = mid + 1, end2 = hi;
        mergeSortCore(nums, copyNum, start1, end1);
        mergeSortCore(nums, copyNum, start2, end2);

        int idx = lo;
        while (start1 <= end1 && start2 <= end2) {
            copyNum[idx++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
        }

        while (start1 <= end1) {
            copyNum[idx++] = nums[start1++];
        }
        while (start2 <= end2) {
            copyNum[idx++] = nums[start2++];
        }

        for (idx=lo; idx<=hi; ++idx) {
            nums[idx] = copyNum[idx];
        }
    }

    void heapSort(std::vector<int> &nums) {
        int nSize = nums.size();
        heapBuild(nums, nSize);
        for (int i=0; i<nSize; ++i) {
            std::swap(nums[0], nums[nSize - i - 1]);
            heapify(nums, 0, nSize - i - 1);
        }
    }

    void heapBuild(std::vector<int> &nums, int nSize) {
        int lastNode = nSize - 1;
        int parent = (lastNode - 1) >> 1;

        for (int i=parent; i>=0; --i) {
            heapify(nums, i, nSize);
        }
    }

    void heapify(std::vector<int> &nums, int idx, int nSize) {
        if (idx >= nSize) {
            return;
        }

        int left = idx * 2 + 1, right = idx * 2 + 2;
        int maxIdx = idx;

        if (left < nSize && nums[left] > nums[maxIdx]) {
            maxIdx = left;
        }
        if (right < nSize && nums[right] > nums[maxIdx]) {
            maxIdx = right;
        }
        if (maxIdx != idx) {
            std::swap(nums[maxIdx], nums[idx]);
            heapify(nums, maxIdx, nSize);
        }
    }
};
}


int main(int argc, char **argv) {
    std::vector<int> nums(10);
    srand(time(NULL));
    for (int i=0; i<10; ++i) {
        nums[i] = (rand() % 10) + 1;
    }

    leetcode_cpp::Solution solu;
    auto ans = solu.sortArray(nums);

    for (int num: ans) {
        std::cout << num << ",";
    }
    std::cout << '\n';

    return 0;
}

