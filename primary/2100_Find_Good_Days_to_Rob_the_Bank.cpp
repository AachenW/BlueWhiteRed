#include <vector>
#include <iostream>

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> goodDaysToRobBank(std::vector<int>& security, int time) {
        int n = security.size();
        std::vector<int> left(n);
        std::vector<int> right(n);
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            if (security[n - i - 1] <= security[n - i]) {
                right[n - i - 1] = right[n - i] + 1;
            }
        }

        std::vector<int> ans;
        for (int i = time; i < n - time; i++) {
            if (left[i] >= time && right[i] >= time) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }  
};
}

int main(int argc, char **argv) {
    std::vector<int> security{5, 3, 3, 3, 5, 6, 2};
    int time = 2;

    auto ans = leetcode_cpp::Solution().goodDaysToRobBank(security, time);

    for (auto &&num: ans) {
        std::cout << num << ",";
    }
    std::cout << std::endl;

    return 0;

}
