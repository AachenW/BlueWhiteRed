#include <vector>
#include <iostream>
#include <ctime>
#include <functional>
#include <iterator>
#include <queue>
/*
@
LeetCode 剑指offer
time: 2022-02-13 21:45:16
author: edinw
@
*/

void printVec(const std::vector<int> &nums) {
    for (const auto &num: nums) {
        std::cout << num << ",";
    }
    std::cout << std::endl;
}

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> getLeastNumbers(std::vector<int>& arr, int k) {
        std::function<void(std::vector<int>&, int, int, int)> quickSort;
        quickSort = [&](std::vector<int> &arr, int lo, int hi, int k) {
            if (lo >= hi) {
                return;
            }
            srand((unsigned)time(NULL));
            int picked = rand() % (hi - lo + 1) + lo;
            int pivot = arr[picked];

            std::swap(arr[lo], arr[picked]);
            
            int left = lo, right = hi;
            while (left < right) {
                while (left < right && arr[right] >= pivot) {
                    --right;
                }
                while (left < right && arr[left] <= pivot) {
                    ++left;
                }
                std::swap(arr[left], arr[right]);
            }

            std::swap(arr[lo], arr[left]);
            int num = left - lo + 1;
            if (k == num) {
                return;
            } else if (k < num) {
                quickSort(arr, lo, left - 1, k);
            } else {
                quickSort(arr, left + 1, hi, k - num);
            }
        };

        quickSort(arr, 0, arr.size() - 1, k);

        std::vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(arr[i]);
        } 

        return ans;
    }
};

class Solution2{
public:
    std::vector<int> getLeastNumbers(std::vector<int>& arr, int k) {
        auto cmp = [](const int num1, const int num2) {
            return num1 < num2;
        };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);

        std::vector<int> ans;
        for (const auto &num: arr) {
            if (pq.size() >= k) {
                if (pq.top() > num) {
                    pq.pop();
                    pq.emplace(num);
                }
            } else {
                pq.emplace(num);
            }
        }
        
        while (!pq.empty()) {
            ans.emplace_back(pq.top());
            pq.pop();
        }

        return ans;

    }
};
}


int main(int argc, char **argv) {
    std::vector<int> arr{0,0,1,2,4,2,2,3,1,4};
    int k = 8;
    auto solution = leetcode_cpp::Solution2();
    auto ans = solution.getLeastNumbers(arr, k);
    std::ostream_iterator<int> outIter(std::cout, " ");
    std::copy(ans.begin(), ans.end(), outIter);

    return 0;
}