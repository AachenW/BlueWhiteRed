template <typename T>
class smart_pointer {
private:
    T *_ptr;
    int *_count;

public:
    // 默认构造函数
    smart_pointer(T *ptr = nullptr) : _ptr(ptr), _count(new int(1)) {}

    // 拷贝构造函数
    smart_pointer(const smart_pointer &other) : _count(&(++*other._count)), _ptr(other._ptr) {}

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


template<class _E>
class initializer_list
{
public:
  typedef _E value_type;
  typedef const _E& reference;
  typedef const _E& const_reference;
  typedef size_t size_type;
  typedef const _E* iterator;
  typedef const _E* const_iterator;

private:
  iterator _M_array;
  size_type _M_len;

  // The compiler can call a private constructor.
  constexpr initializer_list(const_iterator __a, size_type __l)
  : _M_array(__a), _M_len(__l) { }

public:
  constexpr initializer_list() noexcept
  : _M_array(0), _M_len(0) { }

  constexpr size_type size() const noexcept { return _M_len; }
  constexpr const_iterator begin() const noexcept { return _M_array; }
  constexpr const_iterator end() const noexcept { return begin() + size(); }
};

template <typename T>
struct __list_node {
    typedef void * void_pointer;
    void_pointer prev;
    void_pointer next;
    T data;
};

class deque {
    // ... 
protected:
    typedef pointer* map_pointer;
    map_pointer map;
    size_type map_size;

public:
    // ...
    iterator begin();
    iterator end();
}

struct __deque_iterator {
    // ...
    T *cur;
    T *first;
    T *last;
    map_pointer node;
    // ... 
}