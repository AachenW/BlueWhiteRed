#include <iostream>
#include <deque>
#include <vector>
#include <string>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-23 22:13:39
author: edinw
@
*/

/*
**  注意：本题与主站 677 题相同： https://leetcode-cn.com/problems/map-sum-pairs/
** 
**  Design a map that allows you to do the following:
**      Maps a string key to a given value.
**      Returns the sum of the values that have a key with a prefix equal to a given string.
**  Implement the MapSum class:
**      MapSum() Initializes the MapSum object.
**      void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be 
**          overridden to the new one.
**      int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.
*/

namespace leetcode_cpp {
class Trie {
    std::vector<Trie*> children;
    int value;
public:
    Trie() : children(26, nullptr), value(0) {}

    void Insert(const std::string &key, const int &value) {
        Trie *node = this;
        for (const auto &c: key) {
            if (nullptr == node->children[c - 'a']) {
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }
        node->value = value;
    }

    int SumOfPrefix(const std::string &prefix) {
        Trie *node = this;
        for (const auto &c: prefix) {
            if (nullptr == node->children[c - 'a']) {
                return 0;
            }
            node = node->children[c - 'a'];
        }

        // BFS
        int count = 0;
        std::deque<Trie*> queue;
        queue.emplace_back(node);
        while (!queue.empty()) {
            Trie *node = queue.front();
            queue.pop_front();
            count += node->value;
            for (int i = 0; i < node->children.size(); ++i) {
                if (nullptr != node->children[i]) {
                    queue.emplace_back(node->children[i]);
                }
            }
        }
        return count;
    }
};
class MapSum {
    Trie *root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Trie();
    }

    ~MapSum() {
        delete root;
    }
    
    void insert(std::string key, int val) {
        root->Insert(key, val);
    }
    
    int sum(std::string prefix) {
        return root->SumOfPrefix(prefix);
    }
};
}

int main(int argc, char **argv) {
    auto pMapSum = new leetcode_cpp::MapSum();
    pMapSum->insert("apple", 3);
    std::cout << pMapSum->sum("ap") << std::endl;
    pMapSum->insert("app", 2);
    std::cout << pMapSum->sum("ap") << std::endl;

    delete pMapSum;
    return 0;
}