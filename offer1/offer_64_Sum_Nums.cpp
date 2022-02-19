#include <iostream>
#include <functional>

namespace leetcode_cpp {
class Solution {
public:
    int sumNums(int n) {
        std::function<int(int)> backtrack = [&] (int cnt) -> int {
            if (cnt > n) {
                return 0;
            }
            return cnt + backtrack(cnt + 1); 
        };

        return backtrack(0);
    }
};

class Solution2 {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};
}

namespace  vfunc_method {
class A;
A* Array[2];

class A {
public:
    virtual unsigned int Sum(unsigned int n) {
        return 0;
    }
};

class B: public A {
public:
    virtual unsigned int Sum (unsigned int n) {
        return Array[!!n]->Sum(n - 1) + n;
    }
};

int sumNums(int n) {
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int ans = Array[1]->Sum(n);

    return ans;
}
}

namespace funcpoint_method {
typedef unsigned int (*func)(unsigned int n);

unsigned int SolutionTeminator(unsigned int n) {
    return 0;
}

unsigned int SolutionSum(unsigned int n) {
    static func f[2] = {SolutionTeminator, SolutionSum};
    return n + f[!!n](n - 1);
}
}

namespace template_method {
template <unsigned int n> struct sumNum {
    enum Value { 
        N = sumNum<n - 1>::N + n
    };
};

template <> struct sumNum<1> {
    enum Value {
        N = 1
    };
};
}


namespace ctor_method {
class Temp {
public:
    Temp() {
        ++N;
        Sum += N;
    }
    inline static void Reset() {
        N = 0;
        Sum = 0;
    }
    inline static unsigned int GetSum() {
        return Sum;
    }

    int sumNums(int n) {
        Temp::Reset();

        Temp* a = new Temp[n];
        delete[] a;
        a = nullptr;

        return Temp::GetSum();
    }
private:
    static unsigned int N;
    static unsigned int Sum;

};
}


int main(int argc, char** argv) {
    int n = 3;
    std::cout << leetcode_cpp::Solution2().sumNums(n) << std::endl;

    return 0;
}