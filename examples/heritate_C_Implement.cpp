#include <iostream>

struct A {
    virtual void fun() {
        std::cout << "A:fun()" << std::endl;
    }

    int a;
};

struct B: public A {
    virtual void fun() override {
        std::cout << "B:fun()" << std::endl;
    }

    int b;
};


// 用C语言模拟C++的继承与多态
typedef void (*FUN)();  // 定义一个函数指针来实现对成员函数的继承
struct _A {
    FUN _fun;           // 由于C语言中结构体不能包含函数，故只能用函数指针在外面实现
    int _a;
};


struct _B {
    _A _a_; // 在子类中定义一个基类的对象即可实现对父类的继承
    int _b;
};

void _fA() {    // 父类的同名函数 
    printf("_a:_fun()\n");
}

void _fB() {    // 子类的同名函数
    printf("_b:fun()\n");
}

int main(int argc, char **argv) {
    // 测试C++中的继承和多态
    A a;    // 定义一个父类对象a
    B b;    // 定义一个子类对象b

    A *p1 = &a; // 定义一个父类指针指向父类对象
    p1->fun();  // 调用一个父类的同名函数
    p1 = &b;    // 让父类指针指向子类的对象
    p1->fun();  // 调用子类的同名函数

    // C语言模拟继承和多态
    _A _a;  // 定义一个父类对象_a
    _B _b;  // 定义一个子类对象_b
    _a._fun = _fA;  // 父类对象调用父类的同名函数
    _b._a_._fun = _fB;  // 子类对象调用子类的同名函数

    _A *p2 = &_a;   // 定义一个父类指针指向父类的对象
    p2->_fun(); // 调用父类的同名函数
    p2 = (_A*)&_b;  // 让父类指针指向子类的对象，由于类型不匹配所以要进行强制转换
    p2->_fun(); // 调用子类的同名函数
}