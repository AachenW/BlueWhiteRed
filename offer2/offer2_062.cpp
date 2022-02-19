#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <unordered_map>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-21 22:36:26
author: edinw
@
*/

/*
**  注意：本题与主站 208 题相同：https://leetcode-cn.com/problems/implement-trie-prefix-tree/ 
** 
**  Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
**  请你实现 Trie 类：
**      Trie() 初始化前缀树对象。
**      void insert(String word) 向前缀树中插入字符串 word 。
**      boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
**      boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
*/

namespace leetcode_cpp{
class Trie {
    // 保存了对当前结点而言下一个可能出现的所有字符的链接
    std::vector<Trie*> children;
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false) {}
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        Trie *node = this;
        for (char &ch: word) {
            ch -= 'a';
            // 说明父结点的后一个字母不可为 ch
            if (nullptr == node->children[ch]) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        Trie *node = this;
        for (char ch: word) {
            node = node->children[ch - 'a'];
            // 如果出现结点值为空就返回 false
            if (nullptr == node) {
                return false;
            }
        }
        // 如果匹配到了最后一个字符，那我们只需判断 node->isEnd即可。
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        Trie *node = this;
        for (char ch: prefix) {
            node = node->children[ch - 'a'];
            if (nullptr == node) {
                return false;
            }
        }
        // 和 search 操作类似，只是不需要判断最后一个字符结点的isEnd，因为既然能匹配到最后一个字符，那后面一定有单词是以它为前缀的。
        return true;
    }
};
}
