#include <vector>
#include <iostream>
/*
@
projetc: leetcode
time: 2022-01-08 20:51:40
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    /*
    要构造出 n=3 的格雷码，我们首先需要将4个数分别加上 2^(n-1) = 4，再添加到格雷码序列中。也就是 100 101 111 110 这四个数。由于 00 01 11 10 这四个数相邻两个之间只有一位不同； 所以 100 101 111 110 这四个数相邻两个之间也只有一个不同。那只要这两段序列相接的地方，也只有一位不同就可以满足要求了；一种很机智的构造方式就是我们将n=2的四位数加上4，但是倒序拼接。这样构成的 [00 01 11 10 110 111 101 100] 就是一个满足要求的格雷码序列啦。
    */
    std::vector<int> grayCode(int n) {
        std::vector<int> ans;
        ans.emplace_back(0);
        ans.emplace_back(1);

        int delta = 2;
        for (int i = 2; i <= n; ++i) {
            for (int j = delta - 1; j >= 0; --j) {
                ans.emplace_back(ans[j] + delta);
            }
            delta *= 2;
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    int n = 3;
    auto ans = leetcode_cpp::Solution().grayCode(n);
    for (const auto &output : ans) {
        std::cout << output << " ";
    }
    std::cout << std::endl;
    return 0;
}