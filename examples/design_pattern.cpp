#include <iostream>

namespace single_pattern {
// 饿汉模式
// 饿汉模式虽好，但其存在隐藏的问题，在于非静态对象（函数外的static对象）在不同编译单元中的初始化顺序是未定义的。如果在初始化完成之前调用 getInstance() 方法会返回一个未定义的实例。
class SinglePatternHungry {
private:
    SinglePatternHungry() {};
    static SinglePatternHungry *p;

public:
    static SinglePatternHungry* getInstance();

    class CG {
    public:
        ~CG() {
            if (nullptr != SinglePatternHungry::p) {
                delete SinglePatternHungry::p;
                SinglePatternHungry::p = nullptr;
            }
        }
    };
};

SinglePatternHungry* SinglePatternHungry::p = new SinglePatternHungry();
SinglePatternHungry* SinglePatternHungry::getInstance() {
    return p;
}

// 懒汉模式
class SinglePatternLazy {
private:
    static SinglePatternLazy *p;
    SinglePatternLazy() {}

public:
    static SinglePatternLazy* getInstance();
    class CG {
    public:
        ~CG() {
            if (nullptr != SinglePatternLazy::p) {
                delete SinglePatternLazy::p;
                SinglePatternLazy::p = nullptr;
            }
        }
    };
};

// 双检测锁模式，写起来不太优雅，《Effective C++》（Item 04）中的提出另一种更优雅的单例模式实现，使用函数内的局部静态对象，这种方法不用加锁和解锁操作。
// 其实，C++0X以后，要求编译器保证内部静态变量的线程安全性，故C++0x之后该实现是线程安全的，C++0x之前仍需加锁，其中C++0x是C++11标准成为正式标准之前的草案临时名字。
SinglePatternLazy* SinglePatternLazy::p = nullptr;
SinglePatternLazy* SinglePatternLazy::getInstance() {
    static SinglePatternLazy obj;
    return &obj;
}


// 懒汉模式(双重校验锁)
class SinglePatternLazyLock {
private:
    static SinglePatternLazyLock *p;
    SinglePatternLazyLock() {}

public:
    static SinglePatternLazyLock* getInstance();
    class CG {
    public:
        ~CG() {
            if (nullptr != SinglePatternLazyLock::p) {
                delete SinglePatternLazyLock::p;
                SinglePatternLazyLock::p = nullptr;
            }
        }
    };
};

SinglePatternLazyLock* SinglePatternLazyLock::p = nullptr;
SinglePatternLazyLock* SinglePatternLazyLock::getInstance() {
    // 第一层的if检查是因为当实例为空的时候，才去对实例加锁，这样可以避免多次对lock资源的调用
    if (nullptr == p) {
        lock();
        // 当第二层if检测的时候，才是程序要对程序进行初始化。
        if (nullptr == p) {
            p = new SinglePatternLazyLock();
        }
        unlock();
    }
    return p;
}
}

namespace product_factory {
typedef enum productType {
    TypeA,
    TypeB,
    TypeC
} productTypeTag;

class Product {
public:
    virtual void show() = 0;
    virtual ~Product() = 0;
};

class ProductA : public Product {
public:
    void show() {
        std::cout << "ProductA" << std::endl;
    }
    ~ProductA() {
        std::cout << "~ProductA" << std::endl;
    }
};

class ProductB : public Product {
public:
    void show() {
        std::cout << "ProductB" << std::endl;
    }
    ~ProductB() {
        std::cout << "~ProductB" << std::endl;
    }
};

class ProductC : public Product {
public:
    void show() {
        std::cout << "ProductC" << std::endl;
    }
    ~ProductC() {
        std::cout << "~ProductC" << std::endl;
    }
};

class Factory {
public:
    Product* createProduct(productType type) {
        switch (type)
        {
        case TypeA:
            return new ProductA();
            break;
        case TypeB:
            return new ProductB();
            break;
        case TypeC:
            return new ProductC();
            break;
        default:
            return nullptr;
            break;
        }
    }
};
}