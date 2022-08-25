#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-06-09 20:37:47 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    std::vector<int> v_;
    std::vector<std::vector<int>> rects_;

    int area(const std::vector<int> &r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }

public:
    Solution(const std::vector<std::vector<int>> &rects) {
        rects_ = rects;
        for (const auto &r: rects_) {
            v_.emplace_back(area(r) + (v_.empty() ? 0 : v_.back()));
        }
    }

    std::vector<int> pick() {
        int rnd = rand() % v_.back();
        auto it = upper_bound(v_.begin(), v_.end(), rnd);
        int idx = it - v_.begin();
        
        // pick a random point in rect[idx]
        auto r = rects_[idx];
        return {rand() % (r[2] - r[0] + 1) + r[0], rand() % (r[3] - r[1] + 1) + r[1]};
    }
};
}

int main(int argc, char **argv) {
    

}
