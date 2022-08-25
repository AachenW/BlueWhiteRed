#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-04-19 21:24:02 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string reorganizeString(std::string s) {
        int sLen = s.length();
        if (sLen < 2) {
            return s;
        }

        std::vector<int> counts(26, 0);
        int maxCount = 0;
        for (int i=0; i<sLen; ++i) {
            char c = s[i];
            ++counts[c - 'a'];
            maxCount = std::max(maxCount, counts[c - 'a']);
        }
        
        // 如果字母的出现频率最大超过了原字符串长度的一般，则出现频率最大的字母无法满足题意要求
        if (maxCount > (sLen + 1) / 2) {
            return "";
        }

        auto cmp = [&] (const char &c1, const char &c2) {
            return counts[c1 - 'a'] < counts[c2 - 'a'];
        };
        
        // 最大堆堆顶为出现次数最多的字母
        std::priority_queue<char, std::vector<char>, decltype(cmp)> pq(cmp);
        for (char c = 'a'; c <= 'z'; ++c) {
            if (counts[c - 'a']) {
                pq.emplace(c);
            }
        }

        std::string ans{""};
        while (pq.size() > 1) {
            // 取出现频率最多的两个字符，将其添加到字符串中
            char c1 = pq.top(); pq.pop();
            char c2 = pq.top(); pq.pop();
            ans += c1;
            ans += c2;

            int idx1 = c1 - 'a', idx2 = c2 - 'a';
            // 修改字符剩余出现的频率
            --counts[idx1];
            --counts[idx2];
            // 如果字符出现频率还大于0，则加入到大顶堆中
            if (counts[idx1] > 0) {
                pq.emplace(c1);
            }
            if (counts[idx2] > 0) {
                pq.emplace(c2);
            }
        }

        if (!pq.empty()) {
            ans += pq.top();
        }   

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"aab"};

    std::cout << leetcode_cpp::Solution().reorganizeString(s) << '\n';

    return 0;
}
