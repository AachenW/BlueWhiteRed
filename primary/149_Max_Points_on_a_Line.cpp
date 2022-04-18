#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    int maxPoints(std::vector<std::vector<int>> &points) {
        if (points.size() <= 2) {
            return points.size();
        }

        std::map<int, std::map<int, int>> mp;
        int ans = 0;
        
        std::function<int(int, int)> generateGCD = [&] (int a, int b) {
            if (0 == b) {
                return a;
            }
            return generateGCD(b, a % b);
        };

        for (int i = 0; i < points.size(); ++i) {
            mp.clear();
            int localMax = 0, overlap = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];

                // check overlap
                if (0 == x && 0 == y) {
                    ++overlap;
                    continue;
                }

                int gcd = generateGCD(x, y);
                if (0 != gcd) {
                    x /= gcd;
                    y /= gcd;
                }

                // find x, then y
                int curr = ++mp[x][y];
                localMax = std::max(curr, localMax);
            }
            ans = std::max(ans, localMax + overlap + 1);    // +1是因为需要包含point[i]
        }
        return ans;
    }
};
}