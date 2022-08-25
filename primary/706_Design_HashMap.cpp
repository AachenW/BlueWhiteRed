#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-11 19:38:49 
author: edinw
@
*/

namespace leetcode_cpp {
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : data(base) {
    
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if ((*it).first == key) {
                (*it).second = value;
                return;
            }
        }
        data[h].emplace_back(std::make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if ((*it).first == key) {
                return (*it).second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if ((*it).first == key) {
                data[h].erase(it);
                return;
            }
        }
    }

private:
    std::vector<std::list<std::pair<int, int>>> data;
    static const int base = 769;
private:
    static int hash(int key) { return key % base; }
};
}

