#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>
#include <functional>

/*
@
projetc: leetcode
time: 2021-12-15 21:13:38
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> loudAndRich(std::vector<std::vector<int>> &richer, std::vector<int> &quiet) {
        int n = quiet.size();
        std::vector<std::vector<int>> g(n);
        for (auto &r : richer) {
            // 逆转数组，g[x]中所有的结点都是比x富有的结点
            g[r[1]].emplace_back(r[0]);
        }

        std::vector<int> ans(n, -1);
        std::function<void(int)> dfs = [&](int x) {
            // 当ans中结点有值，则直接返回，避免重复计算
            if(ans[x] != -1) {
                return;
            }
            ans[x] = x; // 初始化比自己富有且安静的是自己
            for (int y : g[x]) {    // g[x]中都是比x富有的邻居结点
                dfs(y); // 递归搜索所有比x富有的邻居结点
                if(quiet[ans[y]] < quiet[ans[x]]) { // 当ans[y]中保存的富有且安静的结点(dfs返回的必是自己，即y)，还要比ans[x]中保存的结点安静，则更新ans[x];
                    ans[x] = ans[y];
                }
            }
        };

        for (int i = 0; i < n; ++i) {
            dfs(i); // 挨个搜索每个结点
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> richer {{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    std::vector<int> quite {3,2,5,4,6,1,7,0};

    auto ans = leetcode_cpp::Solution().loudAndRich(richer, quite);

    for (const auto &output : ans) {
        std::cout << output << " ";
    }

}