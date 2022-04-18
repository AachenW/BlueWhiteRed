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
    int key, val;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(key), val(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        head = new DLinkedNode(-1, -1);
        tail = new DLinkedNode(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        } else {
            DLinkedNode *node = cache[key];
            MoveToHead(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            if (cap <= 0) {
                DLinkedNode *deleteNode = RemoveFromTail();
                cache.erase(deleteNode->key);
                delete deleteNode;
                deleteNode = nullptr;
            } else {
                --cap;
            }
        } else {
            DLinkedNode *node = cache[key];
            node->val = value;
            MoveToHead(node);
        }
    }

private:
    void addToHead(DLinkedNode *node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void MoveToHead(DLinkedNode *node) {
        if (node->prev == head) {
            return;
        }
        RemoveNode(node);
        addToHead(node);
    }

    void RemoveNode(DLinkedNode *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    DLinkedNode* RemoveFromTail() {
        DLinkedNode *deleteNode = tail->prev;
        RemoveNode(deleteNode);
        return deleteNode;
    }

private:
    std::unordered_map<int, DLinkedNode*> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int cap;
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
