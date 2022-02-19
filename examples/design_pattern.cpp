#include <iostream>

namespace single_pattern {
// 饿汉模式
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

SinglePatternHungry* SinglePatternHungry::p = nullptr;
SinglePatternHungry* SinglePatternHungry::getInstance() {
    if (nullptr == p) {
        return new SinglePatternHungry();

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