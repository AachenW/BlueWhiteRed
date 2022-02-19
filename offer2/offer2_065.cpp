#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-23 21:03:52
author: edinw
@
*/


/*
**  注意：本题与主站 820 题相同： https://leetcode-cn.com/problems/short-encoding-of-words/
** 
**  A valid encoding of an array of words is any reference string s and array of indices indices such that:
**      ·words.length == indices.length
**      ·The reference string s ends with the '#' character.
**      ·For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i]
**       Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.
*/

namespace leetcode_cpp {
class Trie {
public:
    Trie() : children(26, nullptr), count(0) {}

    Trie* get(const char &c) {
        Trie *node = this;
        if (nullptr == node->children[c - 'a']) {
            node->children[c - 'a'] = new Trie();
            ++count;
        }
        return node->children[c - 'a'];
    }

    void Insert(const std::string &word) {
        Trie *node = this;
        for (const auto &c: word) {
            if (nullptr == node->children[c - 'a']) {
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }
    }

public:
    std::vector<Trie*> children;
    int count;
};

class Solution {
public:
    int minimumLengthEncoding(std::vector<std::string> &words) {
        Trie *root = new Trie();
        std::unordered_map<Trie*, int> nodes;
        for (int i = 0; i < words.size(); ++i) {
            std::reverse(words[i].begin(), words[i].end());
            Trie* cur = root;
            for (const auto &c: words[i]) {
                cur = cur->get(c);
            }
            nodes[cur] = i;
        }

        int ans = 0;
        for (const auto [node, idx]: nodes) {
            if (0 == node->count) {
                ans += words[idx].length() + 1;
            }
        }
        return ans;
    }
};

class Solution2 {
    int total = 0;
public:
    int minimumLengthEncoding(std::vector<std::string> &words) {
        Trie *root = new Trie();
        for (auto &word: words) {
            std::reverse(word.begin(), word.end());
            root->Insert(word);
        }

        int ans = 0;
        backtrack(root, 0);

        delete root;
        return total;
    }

private:
    void backtrack(Trie *node, int len) {
        if (nullptr == node) {
            return;
        }

        for (int i = 0; i < node->children.size(); ++i) {
            bool isLeaf = true;
            if (nullptr != node->children[i]) {
                isLeaf = false;
                backtrack(node->children[i], len + 1);
            }
            if (isLeaf) {
                total += len;
            }
        }
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::string> words {"time", "time", "time"};
    std::cout << leetcode_cpp::Solution2().minimumLengthEncoding(words) << std::endl;
    return 0;
}

/*
时间复杂度：O(∑wi)，其中wi是 words[i] 的长度。对于每个单词中的每个字母，只需要进行常数次操作。空间复杂度：O(S×∑wi)，字典树的空间开销，其中 S 为字符集大小。
*/