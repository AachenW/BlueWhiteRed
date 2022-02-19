#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
/*
@
project: Leetcode
time: 2022-01-23 20:09:33
author: edinw
@
*/

namespace leetcode_cpp {
using pii = std::pair<int, int>;
class StockPrice {
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> minQueue;
    std::priority_queue<pii, std::vector<pii>, std::less<pii>> maxQueue;
    std::unordered_map<int, int> stockState;
    int curStamp;
public:
    StockPrice() : curStamp(0) {

    }

    void update(int timestamp, int price) {
        curStamp = std::max(curStamp, timestamp);
        stockState[timestamp] = price;
        minQueue.emplace(std::make_pair(price, timestamp));
        maxQueue.emplace(std::make_pair(price, timestamp));
    }

    int current() {
        return stockState.at(curStamp);
    }

    int maximum() {
        while (true) {
            auto [price, timestamp] = maxQueue.top();
            if (stockState.at(timestamp) == price) {
                return price;
            }
            maxQueue.pop();
        }
    }

    int minimum() {
        while (true) {
            auto [price, timeStamp] = minQueue.top();
            if (stockState.at(timeStamp) == price) {
                return price;
            }
            minQueue.pop();
        }
    }
};
}

int main(int argc, char **argv) {
    auto stockPrice = new leetcode_cpp::StockPrice();
    stockPrice->update(1, 10);
    stockPrice->update(2, 5);
    stockPrice->current();
    std::cout << stockPrice->maximum() << std::endl;
    stockPrice->update(1, 3);
    std::cout << stockPrice->maximum() << std::endl;
    stockPrice->update(4, 2);
    std::cout << stockPrice->minimum() << std::endl;

    return 0;
}

/*
时间复杂度：初始化的时间复杂度是 O(1)，更新操作、返回股票最高价格操作和返回股票最低价格操作的均摊时间复杂度是 O(logn)，返回股票最新价格操作的时间复杂度是 O(1)，其中 n 是更新操作的次数。更新操作需要更新最大时间戳、哈希表和两个优先队列，更新最大时间戳和哈希表需要 O(1) 的时间。更新操作、返回股票最高价格操作和返回股票最低价格操作中，每个元素分别在两个优先队列中添加和删除一次，平均需要 O(logn) 的时间。返回股票最新价格操作需要在哈希表中得到最大时间戳对应的股票价格，需要 O(1) 的时间。

空间复杂度：O(n)，其中 n 是更新操作的次数。空间复杂度主要取决于哈希表和优先队列，哈希表和每个优先队列中存储的元素个数不会超过更新操作的次数。
*/