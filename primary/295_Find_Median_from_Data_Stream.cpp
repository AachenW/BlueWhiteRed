#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-23 17:49:11
author: edinw
@
*/

namespace leetcode_cpp {
class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.emplace(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.emplace(queMin.top());
                queMin.pop();
            }
        } else {
            queMax.emplace(num);
            if (queMax.size() > queMin.size()) {
                queMin.emplace(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        } else {
            return (queMin.top() + queMax.top()) / 2.0; 
        }
    }

private:
    std::priority_queue<int, std::vector<int>, std::less<int>> queMin;      // 大顶堆，储存较小元素中的最大元素
    std::priority_queue<int, std::vector<int>, std::greater<int>> queMax;   // 小顶堆，储存较大元素中的最小元素
};
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */