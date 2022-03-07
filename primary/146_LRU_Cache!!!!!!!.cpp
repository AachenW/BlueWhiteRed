#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include "../lib/ListNode.h"
#include <unordered_map>
#include <list>

/*
@
LeetCode 热题 HOT 100
time: 2022-02-03 22:54:23
author: edinw
@
*/

/*
**  Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

**  Implement the LRUCache class:

**      LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
**      int get(int key) Return the value of the key if the key exists, otherwise return -1.
**      void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of 
**          keys exceeds the capacity from this operation, evict the least recently used key.
**
**  The functions get and put must each run in O(1) average time complexity.
*/


namespace leetcode_cpp {
struct DLinkedNode {
    int _key, _value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : _key(0), _value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int key, int value) : _key(key), _value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkedNode *node = cache[key];     // 如果key存在, 先通过哈希表定位, 再移到头部
        moveToHead(node);
        return node->_value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode *node = new DLinkedNode(key, value);    // 如果key不存在，创建一个新的节点
            cache[key] = node;  // 添加进哈希表
            addToHead(node);    // 添加至双向链表的头部
            if (size <= 0) {
                DLinkedNode *removed = removeTail();            // 如果超出容量，删除双向链表的尾部节点
                cache.erase(removed->_key);
                delete removed;                                 // 删除哈希表中对应的项
                removed = nullptr;
            } else {
                --size;
            }
        } else {
            DLinkedNode *node = cache[key];                 // 如果key存在，先通过哈希表定位，再修改value，并移到头部
            node->_value = value;
            moveToHead(node);
        }
    }
private:
    void moveToHead(DLinkedNode *node) {
        if(node->prev == head) {
            return;
        }
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
    }

    DLinkedNode* removeTail() {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }

private:
    std::unordered_map<int, DLinkedNode*> cache;
    int size;
    int capacity;
    DLinkedNode *head;
    DLinkedNode *tail;
};

struct Node
{
    Node(int k = 0, int v = 0) : key(k), value(v) {}
    int key;
    int value;
};
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    void add(int key, int val) {
        L.emplace_front(new Node(key, val));
        H[key] = L.begin();
        if (L.size() > cap) {
            auto last = L.end();
            --last;
            remove(last);
        }
    }

    int remove(std::list<Node*>::iterator &iter) {
        int key = (*iter)->key;
        int val = (*iter)->value;
        L.erase(iter);
        H.erase(key);
        return val;
    }

    void set(int key, int val) {
        auto iter = H.find(key);
        if (iter != H.end()) {
            remove(iter->second);
        }
        add(key, val);
    }

    int get(int key) {
        int val = 0;
        auto iter = H.find(key);
        if (iter != H.end()) {
            val = remove(iter->second);
            add(key, val);
            return val;
        }
        return -1;
    }

private:
    int cap;
    std::list<Node*> L;
    std::unordered_map<int, std::list<Node*>::iterator> H;
};
}
