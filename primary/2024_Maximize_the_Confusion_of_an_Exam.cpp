#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-03-29 17:07:28
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
private:
    int maxConsecutiveChar(std::string &answerKey, int k, char ch) {
        int n = answerKey.length();
        int ans = 0;
        for (int left = 0, right = 0, sum = 0; right < n; ++right) {
            sum += answerKey[right] != ch;
            while (sum > k) {
                sum -= answerKey[left++] != ch;
            }
            ans = std::max(right - left + 1, ans);
        }

        return ans;
    }

public:
    int maxConsecutiveAnswers(std::string answerKey, int k) {
        return std::max(maxConsecutiveChar(answerKey, k, 'T'), maxConsecutiveChar(answerKey, k, 'F'));
    }

};
}