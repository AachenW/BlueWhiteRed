#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
/*
@
project: Leetcode
time: 2021-12-24 09:51:57
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    typedef std::pair<int, int> pii;
    int eatednApples(std::vector<int> &apple, std::vector<int> &days) {
        int ans = 0;
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> que;
        typedef decltype(apple.size()) sz;
        sz appleLength = apple.size();
        sz i = 0;
        while (i < appleLength) {
            while (!que.empty() && que.top().first <= i) {
                que.pop();                      // 苹果已经腐烂
            }
            int rottenDay = i + days[i];        // 保质期限
            int count = apple[i];
            if (count > 0) {
                que.emplace(rottenDay, count);  // 将[保质期限, 苹果数量]加入优先队列中
            }
            if (!que.empty()) {
                pii curr = que.top();           // 从优先队列头取出此刻[保质期限, 苹果数量]
                que.pop();
                --curr.second;                  // 今天吃掉一个苹果
                if (curr.second != 0) {         // 如果今天取出的[保质期限, 苹果数量]还有剩余
                    que.emplace(curr.first, curr.second);   // 将剩余的[保质期限, 苹果数量]继续加入优先队列中去
                }
                ++ans;
            }
            ++i;
        }

        while (!que.empty()) {
            while (!que.empty() && que.top().first <= i) {
                que.pop();
            }
            if (que.empty()) {
                break;
            }
            pii curr = que.top();
            que.pop();
            int num = std::min(curr.first - i, (size_t)(curr.second));
            ans += num;
            i += num;
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> apple {2, 1, 10}, days {2, 10, 1};
    std::cout << leetcode_cpp::Solution().eatednApples(apple, days) << std::endl;
    return 0;
}