#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-25 10:19:43
author: edinw
@
*/

namespace leetcode_cpp {
class Trie {
public:
    Trie() : children(26), isEnd(0) {}

    void insert(std::string &word) {
        Trie *node = this;
        for (char c: word) {
            c -= 'a';
            if (nullptr == node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = 1;
    }

    int search(std::string &word) {
        Trie *node = this;
        for (char c: word) {
            c -= 'a';
            if (nullptr == node->children[c]) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEnd;
    }

    int startWith(std::string &prefix) {
        Trie *node = this;
        for (char c: prefix) {
            c -= 'a';
            if (nullptr == node->children[c]) {
                return 0;
            }
            node = node->children[c];
        }
        return 1;
    }
private:
    std::vector<Trie*> children;
    int isEnd;
};
}