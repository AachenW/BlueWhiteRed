#include <vector>
#include <unordered_map>
#include <list>

/*
@
project: leetcode
time: 2022-02-28 22:26:02
author: edinw
@
*/

struct Node{
    int key, val, freq;
    Node(int _key, int _val, int _freq): key(_key), val(_val), freq(_freq) {}
};

namespace leetcode_cpp {
class LFUCache {
    int minfreq, capacity;
    std::unordered_map<int, std::list<Node>::iterator> key_table;
    std::unordered_map<int, std::list<Node>> freq_table;
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }

    int get(int key) {
        if (0 == capacity) {
            return -1;
        }
        auto iter = key_table.find(key);
        if (iter == key_table.end()) {
            return -1;
        }

        std::list<Node>::iterator node = iter->second;
        int val = node->val, freq = node->freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (0 == freq_table[freq].size()) {
            freq_table.erase(freq);
            if (minfreq == freq) {
                minfreq += 1;   // 使用频率最低的list中所有节点全部被删除，所以minfreq更新为minfreq+1
            }
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].emplace_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();      // 指向相同频次列表中的最近访问过的节点
        return val;
    }

    void put(int key, int value) {
        if (0 == capacity) {
            return;
        }
        auto iter = key_table.find(key);
        if (iter == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过minFreq拿到freq_table[minFreq]链表的末尾节点
                auto iter2 = freq_table[minfreq].back();
                key_table.erase(iter2.key);
                freq_table[minfreq].pop_back();
                if (0 == freq_table[minfreq].size()) {
                    freq_table.erase(minfreq);
                }
            }
            freq_table[1].emplace_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            std::list<Node>::iterator node = iter->second;
            int freq = node->freq;
            freq_table[freq].erase(node);
            if (0 == freq_table[freq].size()) {
                freq_table.erase(freq);
                if (minfreq == freq) {
                    minfreq += 1;
                }
            }
            freq_table[freq + 1].emplace_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};
}