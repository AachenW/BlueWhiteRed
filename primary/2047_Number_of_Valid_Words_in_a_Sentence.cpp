#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
#include <unordered_set>
/*
@
project: Leetcode
time: 2022-01-27 20:07:55
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int countValidWords(std::string sentence) {
        int sLen = sentence.length();
        int lo = 0, hi = 0;
        int count = 0;
        auto words = split(sentence);

        for (const auto &word: words) {
            if (isValidWord(word)) {
                ++count;
            }
        }
        return count;
    }

private:
    // 检查每个word是否满足token要求
    bool isValidWord(std::string word) {
        int wLen = word.length();
        int punc = 0;
        int concat = 0;
        for (int i = 0; i < wLen; ++i) {
            // Condition 1: 仅由小写字母、连字符和/或标点（不含数字）
            if (word[i] >= '0' && word[i] <= '9') {
                return false;
            }
            // 至多一个 连字符 '-' 。如果存在，连字符两侧应当都存在小写字母
            else if ('-' == word[i]) {
                if (1 == concat || 0 == i || wLen - 1 == i) {
                    return false;
                } else if (word[i + 1] < 'a' || word[i + 1] > 'z') {
                    return false;
                }
                concat = 1;
            }
            // 至多一个 标点符号。如果存在，标点符号应当位于 token 的 末尾
            else if ('!' == word[i] || '.' == word[i] || ',' == word[i]) {
                if (punc || wLen - 1 != i) {
                    return false;
                } 
                punc = 1;
            }
        }
        return true;
    }

    // 将sentence根据空格分解成多个word
    std::vector<std::string> split(std::string sentence) {
        std::vector<std::string> ans;
        std::string temp;
        int i = 0;

        // 过滤掉前导空格
        while (' ' == sentence[i]) {
            ++i;
        }
        for (; i < sentence.length(); ++i) {
            char ch = sentence[i];
            if (' ' == ch) {
                while (' ' == sentence[i + 1]) {
                    ++i;
                }
                ans.emplace_back(temp);
                temp.clear();
            } else {
                temp.push_back(ch);
            }
        }
        if (!temp.empty()) {
            ans.emplace_back(temp);
        }
        return ans;
    }
};
}


int main(int argc, char **argv) {
    std::string sentence{" 62   nvtk0wr4f  8 qt3r! w1ph 1l ,e0d 0n 2v 7c.  n06huu2n9 s9   ui4 nsr!d7olr  q-, vqdo!btpmtmui.bb83lf g .!v9-lg 2fyoykex uy5a 8v whvu8 .y sc5 -0n4 zo pfgju 5u 4 3x,3!wl  fv4   s  aig cf j1 a i  8m5o1  !u n!.1tz87d3 .9    n a3  .xb1p9f  b1i a j8s2 cugf l494cx1! hisceovf3 8d93 sg 4r.f1z9w   4- cb r97jo hln3s h2 o .  8dx08as7l!mcmc isa49afk i1 fk,s e !1 ln rt2vhu 4ks4zq c w  o- 6  5!.n8ten0 6mk 2k2y3e335,yj  h p3 5 -0  5g1c  tr49, ,qp9 -v p  7p4v110926wwr h x wklq u zo 16. !8  u63n0c l3 yckifu 1cgz t.i   lh w xa l,jt   hpi ng-gvtk8 9 j u9qfcd!2  kyu42v dmv.cst6i5fo rxhw4wvp2 1 okc8!  z aribcam0  cp-zp,!e x  agj-gb3 !om3934 k vnuo056h g7 t-6j! 8w8fncebuj-lq    inzqhw v39,  f e 9. 50 , ru3r  mbuab  6  wz dw79.av2xp . gbmy gc s6pi pra4fo9fwq k   j-ppy -3vpf   o k4hy3 -!..5s ,2 k5 j p38dtd   !i   b!fgj,nx qgif "};
    std::cout << leetcode_cpp::Solution().countValidWords(sentence) << std::endl;
    return 0;
}