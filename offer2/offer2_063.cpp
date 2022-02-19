#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <unordered_map>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-22 21:56:42
author: edinw
@
*/

/*
**  注意：本题与主站 648 题相同： https://leetcode-cn.com/problems/replace-words/
** 
**  In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. 
**  For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
**  Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with 
**  the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
**  Return the sentence after the replacement.
*/

namespace leetcode_cpp {
class Trie {
    std::vector<Trie*> children;
    bool isEnd;
public:
    Trie() : children(26, nullptr), isEnd(false) {}

    void Insert(const std::string &str) {
        Trie *node = this;
        for (char c: str) {
            c -= 'a';
            if (nullptr == node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }

    int countPrefixLen(const std::string &str) {
        Trie *node = this;
        int len = 0;
        for (char c: str) {
            c -= 'a';
            if (nullptr == node->children[c]) {
                return 0;
            }
            node = node->children[c];
            ++len;
            if (node->isEnd) {
                return len;
            }
        }
        return 0;
    }
};

class Solution {
public:
    std::string replaceWords(std::vector<std::string> &dictionary, std::string sentence) {
        Trie *root = new Trie();
        for (const auto &word: dictionary) {
            root->Insert(word);
        }

        // 分割
        std::vector<std::string> words;
        std::string temp;
        for (const auto &ch: sentence) {
            if (ch == ' ') {
                words.emplace_back(temp);
                temp.clear();
            } else {
                temp.push_back(std::move(ch));
            }
        }
        if (temp.length()) {
            words.emplace_back(temp);
        }

        // 处理
        std::vector<std::string> ans;
        for (const auto &word: words) {
            int len = root->countPrefixLen(word);
            if (0 == len) {
                ans.emplace_back(word);
            } else {
                ans.emplace_back(word.substr(0, len));
            }
        }

        // concatenate
        std::string ret;
        for (const auto &word: ans) {
            ret += word;
            ret += " ";
        }
        ret.pop_back();

        return ret;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::string> dictionary {"cat","bat","rat"};
    std::string sentence {"the cattle was rattled by the battery"};
    std::cout << leetcode_cpp::Solution().replaceWords(dictionary, sentence) << std::endl;
    return 0;
}