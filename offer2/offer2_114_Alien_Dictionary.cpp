#include <bits/stdc++.h>

/*
@
LeetCode 剑指offerⅡ
time: 2022-05-31 10:54:12
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    constexpr static int VISITING = 1, VISITED = 2;
    std::unordered_map<char, std::vector<char>> edges;
    std::unordered_map<char, int> states;
    int valid = 1;
    std::string order;
    int idx;

public:
    std::string alienOrder(std::vector<std::string>& words) {
        int length = words.size();
        for (const auto& word: words) {
            int wordLength = word.size();
            for (int j = 0; j < wordLength; ++j) {
                char c = word[j];
                if (!edges.count(c)) edges[c] = std::vector<char>{};
            }
        }

        for (int i = 1; i < length && valid; ++i) {
            addEdge(words[i - 1], words[i]);
        }
        order = std::string(edges.size(), ' ');
        idx = edges.size() - 1;
        for (auto [u, _]: edges) 
            if (!states.count(u)) dfs(u);

        if (!valid) return "";

        return order;
    }

private:
    void addEdge(std::string before, std::string after) {
        int length1 = before.size(), length2 = after.size();
        int length = std::min(length1, length2);
        int idx = 0;
        while (idx < length) {
            char c1 = before[idx], c2 = after[idx];
            if (c1 != c2) {
                edges[c1].emplace_back(c2);
                break;
            }
            ++idx;
        }
        if (idx == length && length1 > length2) valid = false;
    }

    void dfs(char u) {
        states[u] = VISITING;
        for (char v: edges[u]) {
            if (!states.count(v)) {
                dfs(v);
                if (!valid) return;
            } else if (states[v] == VISITING){
                valid = false;
                return;
            }
        }
        states[u] = VISITED;
        order[idx] = u;
        --idx;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::string> words{"wrt", "wrf", "er", "ett", "rftt"};
    std::cout << leetcode_cpp::Solution().alienOrder(words) << std::endl;
    return 0;
}
