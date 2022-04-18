#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int span = getCount(curr, n);
            if (span <= k) {
                k -= span; 
                ++curr;
            } else {
                curr = curr * 10;
                --k;
            }
        }

        return curr;
    }

private:
    // 以curr为前缀，在给定范围内有多少个数
    int getCount(int curr, long n) {
        int span = 0;
        long first = curr, last = curr;

        while (first <= n) {
            span += std::min(n, last) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }

        return span;
    }
};
}

int main(int argc, char **argv) {
    int n = 13, k = 2;
    
    std::cout << leetcode_cpp::Solution().findKthNumber(n, k) << std::endl;
    
    return 0;
}