#include "stdlib.h"
#include "stdint.h"

// __attribute__ ((__packed__)) 告诉编译器取消结构体在编译过程中的优化对⻬，按照实际占⽤字节数进⾏对⻬。
struct __attribute__ ((__packed__)) sdshdr16 {
    uint16_t len;
    uint16_t alloc;
    unsigned char flags;
    char buf[];
};

// 链表节点
typedef struct listNode {
    listNode *prev;
    listNode *next;
    void *value;
} listNode;

// 链表结构设计
typedef struct list {
    // 链表头结点
    listNode *head;
    // 链表尾节点
    listNode *tail;
    // 节点值复制函数
    void *(*dup)(void *ptr);
    // 节点值释放函数
    void (*free)(void *ptr);
    // 节点值比较函数
    int (*match)(void *ptr, void*key);
    // 链表节点数量
    unsigned long len;
}list;

// 哈希表
typedef struct dictht {
    // 哈希表数组
    dictEntry **table;
    // 哈希表大小
    unsigned long size;
    // 哈希表大小掩码，用于计算索引值
    unsigned long sizemask;
    // 该哈希表已有的节点数量
    unsigned long used;
} dictht;

// 哈希表节点的结构如下
typedef struct dictEntry {
    // 键值对中的键
    void *key;
    // 键值对中的值
    union {
        void *val;
        uint16_t u64;
        int64_t s64;
        double d;
    } v;
    // 指向下一个哈希表节点，形成链表
    struct dictEntry *next;
    
} dictEntry;

typedef struct dict {
    ...
    // 两个哈希表，交替使用，用于rehash操作
    dictht ht[2];
    ...
}dict;

// 整数集合结构设计
typedef struct intset {
    // 编码方式
    uint32_t encoding;
    // 集合包含的元素数量
    uint32_t length;
    // 保存元素的数组
    int8_t contents[];
} intset;

typedef struct zset {
    dict *dict;
    zskiplist *zsl;
} zset;

typedef struct zskpilistNode {
    // Zset对象的元素值
    sds ele;
    // 元素权重值
    double score;
    // 后向指针
    struct zskpilistNode *backward;

    // 节点的level数组，保证每层上的前向指针和跨度
    struct zskiplistLevel {
        struct zskiplistNode *forward;
        unsigned long span;
    } level[];
} zskpilistNode;

typedef struct zskiplist {
    struct zskiplistNode *header, *tail;
    unsigned long length;
    int level;
} zskiplist;


// quicklist
typedef struct quicklist {
    // quicklist的链表头
    quicklistNode *head;
    // quicklist的链表尾
    quicklistNode *tail;
    // 所有压缩列表中的总元素个数
    unsigned long count;
    // quicklistNodes的个数
    unsigned long len;
    ...
} quicklist;

typedef struct quicklistNode {
    // 前一个quicklistNode
    struct quicklistNode *prev;
    // 下一个quicklistNode
    struct quicklistNode *next;
    // quicklistNode指向的压缩列表
    unsigned char *zl;
    // 压缩列表的字节大小
    unsigned int sz;
    // 压缩列表的元素个数
    unsigned int count : 16;    // ziplist中的元素个数
    ...
} quicklistNode;