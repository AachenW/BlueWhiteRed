template <typename T>
class smart_pointer {
private:
    T *_ptr;
    int *_count;

public:
    // 默认构造函数
    smart_pointer() : _ptr(nullptr), _count(0) {}

    // 初始构造函数
    smart_pointer(T *ptr) : _ptr(ptr){
        if (_ptr) {
            _count = new int(1);
        } else {
            _count = new int(0);
        }
    }

    // 拷贝构造函数
    smart_pointer(const smart_pointer *ptr) {
        if (ptr != this) {
            this->_ptr = ptr->_ptr;
            this->_count = ptr->_count;
            ++(*this->_count);
        }
    }

    // 赋值构造函数
    smart_pointer& operator=(const smart_pointer &ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }
        if (this->_ptr) {
            --(*this->_count);
            if (0 == *this->_count) {
                delete this->_ptr;
                delete this->_count;
            }
        }

        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        ++(this->_count);
    }

    // 析构函数
    ~smart_pointer() {
        --(*this->_count);
        if (0 == *this->_count) {
            delete this->_ptr;
            delete this->_count;
        }
    }

    T* operator->() {
        return this->_ptr;
    }

    T& operator*() {
        return *this->_ptr;
    }

    int use_count() {
        return this->_count;
    }

    T* get() {
        return this->_ptr;
    }
};