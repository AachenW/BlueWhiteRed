#include <stdio.h>

template <class T, class Alloc = std::alloc>
class vector {
public:
    typedef T           value_type;
    typedef value_type* pointer;
    typedef value_type* iterator;
    typedef value_type& reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference_type;

protected:
    typedef simple_alloc<value_type, Alloc> data_allocator;

    iterator start;             // 表示目前使用空间的头
    iterator finish;            // 表示目前使用空间的尾
    iterator end_of_storage;    // 表示目前可用空间的尾

    // ...
};

template <class T>
struct __list_node {
    typedef void* void_pointer;
    void_pointer prev;  // 类型为void*，其实可以设为__list_node<T>*
    void_pointer next;
    T data;
};

template <class T, class Alloc = alloc>
class list {
protected:
    typedef __list_node<T> list_node;
public:
    typedef list_node* link_type;

protected:
    link_type node; // 只要一个指针，就可以表示整个环状双向链表
};


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
};

struct __deque_iterator {
    // ...
    T *cur;
    T *first;
    T *last;
    map_pointer node;
    // ... 
};

