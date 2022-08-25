#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-19 16:44
author: edinw
@
*/

namespace leetcode_cpp {
class FreqStack {
public:
    FreqStack() : maxFreq(0) {}

    void push(int x) {
        maxFreq = std::max(maxFreq, ++freq[x]);
        m[freq[x]].push_back(x);
    }

    int pop() {
        int x = m[maxFreq].back(); m[maxFreq].pop_back();
        /* First, pay attention to the meaning of map m, it stores <frequency, a stack contains all elements which was pushed frequency times>, therefore, it's guaranteed that the keys of map m will be consecutively increasing, from 1 to maxfreq without gap. For example, when all elements that appeared 3 times have been popped out, we start checking the stack for all elements that appeared 2 times. In short, an element will appear in all stacks which have a key freq <= element's freq.
        */
        if (!m[freq[x]--].size()) --maxFreq;
        return x;
    }

private:
    std::unordered_map<int, int> freq;  // count the frequence of elements
    std::unordered_map<int, std::deque<int>> m; // it stores <frequency, a stack contains all elements which was pushed frequency times>
    int maxFreq;    // record the maximum frequence
};
}
