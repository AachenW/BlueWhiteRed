#include <iostream>
#include <deque>
#include <vector>
#include <string>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-22 22:46:52
author: edinw
@
*/

/*
**  注意：本题与主站 676 题相同： https://leetcode-cn.com/problems/implement-magic-dictionary/
** 
**  Design a data structure that is initialized with a list of different words. Provided a string, you should determine if you can change exactly one 
**  character in this string to match any word in the data structure.
**  Implement the MagicDictionary class:
**      MagicDictionary() Initializes the object.
**      void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
**      bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, 
**      otherwise returns false.
*/

namespace leetcode_cpp {
class Trie {
public:
    Trie() : children(26, nullptr), isEnd(false) {

    }

    void Insert(const std::string &word) {
        Trie *node = this;
        for (auto ch: word) {
            ch -= 'a';
            if (nullptr == node->children[ch]) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    void search(const std::string &word) {
        Trie *node = this;
        for (auto ch: word) {
            ch -= 'a';
            if (nullptr == this->children[ch]) {

            }
        }
    }

public:
    std::vector<Trie*> children;
    bool isEnd;
};

class MagicDictionary {
    Trie *root;
public:
    MagicDictionary() : root(nullptr) {}

    void buildDict(std::vector<std::string> dictionary) {
        root = new Trie();
        for (const auto &dic: dictionary) {
            root->Insert(dic);
        }
    }

    bool search(std::string searchWord) {
        int pos = 0, edit = 0;
        return backtrack(root, searchWord, pos, edit);
    }

private:
    // pos为word的当前字符位置
    bool backtrack(Trie *root, std::string &word, int pos, int &edit) {
        if (nullptr == root) {
            return false;
        }

        // 如果到达对应字符串的最后一个字符所对应的节点，且该节点的 isEnd 为 ture, 并且当前路径刚好修改了字符串中的一个字符
        if (root->isEnd && pos == word.size() && edit == 1) {
            return true;
        }

        if (pos < word.size() && edit <= 1) {
            for (int j = 0; j < 26; ++j) {
                // 如果子节点存在，edit不变；否则，edit加1；
                int next = (j == word[pos] - 'a') ? edit : edit + 1;
                if (backtrack(root->children[j], word, pos + 1, next)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
}

int main(int argc, char **argv) {
    leetcode_cpp::MagicDictionary *magicDict = new leetcode_cpp::MagicDictionary();
    std::vector<std::string> strs {"hello", "leetcode"};
    magicDict->buildDict(strs);
    std::cout << std::boolalpha << magicDict->search("hello") << std::endl;
    std::cout << magicDict->search("hhllo") << std::endl;
    std::cout << magicDict->search("hell") << std::endl;
    std::cout << magicDict->search("leetcoded") << std::endl;
    return 0;
}