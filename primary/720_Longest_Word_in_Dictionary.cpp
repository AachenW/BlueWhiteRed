#include <vector>
#include <string>
/*
@
Leetcode
time: 2022-03-17 08:55:28
author: edinw
@
*/

namespace leetcode_cpp {
class Trie {
private:
    std::vector<Trie*> children;
    int isEnd;

public:
    Trie () {
        this->children = std::vector<Trie*>(26, nullptr);
        this->isEnd = false;
    }

    bool insert(const std::string &s) {
        Trie *node = this;
        for (char c: s) {
            int idx = c - 'a';
            if (nullptr == node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
        return true;
    }

    bool search(const std::string &word) {
        Trie *node = this;
        for (char c: word) {
            int idx = c - 'a';
            if (nullptr == node->children[idx] || false == node->children[idx]->isEnd) {
                return false;
            }
            node = node->children[idx];
        }

        return nullptr != node && node->isEnd;
    }
};

class Solution {
public:
    std::string longestWord(std::vector<std::string>& words) {
        Trie trie;
        for (const auto &word: words) {
            trie.insert(word);
        }

        std::string longest = "";
        for (const auto &word: words) {
            if (trie.search(word)) {
                if (word.length() > longest.length() || (word.length() == longest.length() && word < longest)) {
                    longest = word;
                }
            }
        }

        return longest;
    }
};    
}