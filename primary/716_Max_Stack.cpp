#include <bits/stdc++.h>

namespace leetcode_cpp {
class MaxStack {
    // initialize your data structure here.
    MaxStack() {}

    void push(int x) {
        list.insert(list.begin(), x);   // 头插
        map[x].emplace_back(list.begin());
    }

    int pop() {
        auto x = *list.begin();
        map[x].pop_back();  // 删除map中的迭代器
        if (map[x].empty()) {
            map.erase(x);
        }
        list.erase(list.begin());
        return x;
    }

    int top() {
        return *list.begin();
    }

    int peekMax() {
        return map.rbegin()->first; // 最大值
    }

    int popMax() {
        auto x = map.rbegin()->first;   // 最大值
        auto it = map[x].back();    // 最大值中最靠近栈顶的迭代器
        map[x].pop_back();  // 删除迭代器
        if (map[x].empty()) {
            map.erase(x);
        }
        list.erase(it);
        return x;
    }


private:
    std::list<int> list;
    std::map<int, std::vector<std::list<int>::iterator>> map;   // vector为相同值的迭代器集合，尾部为最靠近栈顶的
};
}