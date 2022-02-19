#include <iostream>
#include <functional>


namespace leetcode_cpp {
class Solution {
public:
    double myPow(double x, int n) {
        std::function<double(double, int)> backtrack = [&](double x, long long n) -> double {
            if (0 == n) {
                return 1.0;
            }
            if (1 == n) {
                return x;
            }

            double ans = backtrack(x, n / 2);   

            return n & 1 ? ans * ans * x : ans * ans;
        };
        long long nLong = n;
        return n < 0 ? 1.0 / backtrack(x, -nLong) : backtrack(x, nLong);
    }
};

class Solution2 {
public:
    double myPow(double x, int n) {
        long long nLong = n;
        std::function<double(double, long long)> backtrack = [&](double x, long long n) -> double {
            double ans = 1.0;
            double x_contribute = x;
            while (n > 0) {
                if (n & 1) {
                    ans *= x_contribute;
                }
                x_contribute *= x_contribute;
                n /= 2;
            }
            return ans;
        };

        return n < 0 ? 1.0 / backtrack(x, -n) : backtrack(x , n);
    }
};
}

int main(int argc, char **argv) {
    int n = -2147483648;
    double x = 2.0;
    std::cout << leetcode_cpp::Solution().myPow(x, n) << std::endl;
    return 0;
}