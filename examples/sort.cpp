#include <vector>
#include <functional>
#include <iostream>

namespace sorting_algorithm {
// 算法平均时间复杂度O(nlogn)，最坏情况(初始数组倒序排列)可能达到O(n^2)，空间复杂度O(logn)
void quickSort(std::vector<int> &nums) {
    std::function<void(std::vector<std::string>&, int, int)> quickSort;
    quickSort = [&](std::vector<std::string> &strs, int lo, int hi) {
        int selected = rand() % (hi - lo + 1) + lo;
        std::string pivot = strs[selected];

        std::swap(strs[lo], strs[selected]);
        int left = lo, right = hi;
        while (left < right) {
            while (strs[right] + pivot >= pivot + strs[right] && left < right) {
                --right;
            }
            while (strs[left] + pivot <= pivot + strs[left] && left < right) {
                ++left;
            }
            std::swap(strs[left], strs[right]);
        }

        std::swap(strs[lo], strs[left]);

        quickSort(strs, lo, left - 1);
        quickSort(strs, left + 1, hi);
    };
}

// 时间复杂度O(n^2), 空间O(1), 原地算法，稳定
void bubbleSort(std::vector<int> &nums) {
    int nSize = nums.size();
    for (int i = 0; i < nSize; ++i) {
        for (int j = 0; j < nSize - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void bubbleSort2(std::vector<int> &nums) {
    int nSize = nums.size();
    bool flag = false;
    for (int i = 0; i < nSize - 1; ++i) {
        flag = false;
        for (int j = 0; j < nSize - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                flag = true;
                std::swap(nums[j], nums[j + 1]);
            }
        }

        if (!flag) {
            break;
        }
    }
}

// 时间负复杂度：O(n^2)，空间O（1），非稳定排序，原地排序
void selectSort(std::vector<int> &nums) {
    int nSize = nums.size();
    int minIndex = -1;
    for (int i = 0; i < nSize - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < nSize; ++i) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(nums[i], nums[minIndex]);
    }
}

// 时间复杂度 O(n^2) 空间 O(1)，稳定排序，原地排序
void insertSort(std::vector<int> &nums) {
    int nSize = nums.size();
    for (int i = 1; i < nSize; ++i) {
        // 每一轮此中，nums[0, ..., i - 1]是有序的，所以要在有序子序列中找到当前元素的插入位置
        if (nums[i] < nums[i - 1]) {
            int j = i - 1;
            int x = nums[i];                    // 复制为哨兵，即存储待排序元素
            while (j >= 0 && x < nums[j]) {     // 查找在有序表的插入位置,还必须要保证j是>=0的, 因为a[j]要合法
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = x;
        }
    }
}

void mergeSort(std::vector<int> &nums, std::vector<int> &temp, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int nSize = hi - lo + 1, mid = lo + ((hi - lo) >> 1);
    int start1 = lo, end1 = mid, start2 = mid + 1, end2 = hi;
    mergeSort(nums, temp, start1, end1);
    mergeSort(nums, temp, start2, end2);
    int idx = lo;
    while (start1 <= end1 && start2 <= end2) {
        temp[idx++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
    }
    while (start1 <= end1) {
        temp[idx++] = nums[start1++];
    }

    while (start2 <= end2) {
        temp[idx++] = nums[start2++];
    }
}

void mergeSort(std::vector<int> nums) {
    std::vector<int> copyNums(nums);//这里要借助一个一模一样的数组的
    mergeSort(nums, copyNums, 0, nums.size() - 1);
    nums.assign(copyNums.begin(), copyNums.end());//到最后copy数组是排序好的，记得要赋值一下
    for (auto a : nums) {
        std::cout << a << " ";
    }
}

// 对有一定顺序的堆，当前第i个结点取根左右的最大值（这个操作称heapfiy）
void heapify(std::vector<int> &nums, int n, int i) {
    if (i >= n) {
        return;
    }
    int left = i * 2 + 1, right = i * 2 + 2;
    int max = i;
    if (left < n && nums[left] > nums[max]) {
        max = left;
    }
    if (right < n && nums[left] < nums[max]) {
        max = right;
    }
    if (max != i) {
        std::swap(nums[max], nums[i]);
        heapify(nums, n, max);
    }
}

// 建立大根堆，从树的倒数第二层第一个结点开始，对每个结点进行heapify操作，然后向上走
void heapify_build(std::vector<int> &nums, int n) {
    int last_node = n - 1;
    int parent = (last_node - 1) / 2;         // 树的倒数第二层第一个结点
    for (int i = parent; i >= 0; --i) {
        heapify(nums, n, i);
    }
}

// 建立大根堆之后，每次交换最后一个结点和根节点（最大值），对交换后的根节点继续进行heapify（此时堆的最后一位是最大值，因此不用管他，n变为n-1）
void heapify_sort(std::vector<int> &nums, int n) {
    heapify_build(nums, n);
    for (int i = 0; i < n; ++i) {
        std::swap(nums.front(), nums[n - i - 1]);
        heapify(nums, n - i - 1, 0);
    }
}


// 希尔排序
void shellSortCore(std::vector<int> &nums, int gap, int i) {
    int inserted = nums[i];
    int j = 0;
    // 插入时按组进行插入
    for (j = i - gap; j >= 0 && inserted < nums[j]; j-= gap) {
        nums[j + gap] = nums[j];
    }
    nums[j + gap] = inserted;
}

void sheelSort(std::vector<int> nums) {
    int len = nums.size();
    // 进行分组，最开始的时候，gap为数组长度的一半
    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; ++i) {
            shellSortCore(nums, gap, i);
        }
    }
}

// 归并排序

}
