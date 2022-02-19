#include <vector>
#include <iostream>
#include <ctime>
#include <functional>
#include <iterator>
#include <queue>
/*
@
LeetCode 剑指offer
time: 2022-02-13 23:39:47
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
    std::priority_queue<int, std::vector<int>, std::less<int>> queMin;      // 大顶堆，储存较小的元素
    std::priority_queue<int, std::vector<int>, std::greater<int>> queMax;   // 小顶堆，储存较大的元素
};
}

int main(int argc, char **argv) {
    auto finder = new leetcode_cpp::MedianFinder();
    finder->addNum(1);
    finder->addNum(2);
    std::cout << finder->findMedian() << std::endl;
    finder->addNum(3);
    std::cout << finder->findMedian() << std::endl;
    delete finder;
    return 0;
}