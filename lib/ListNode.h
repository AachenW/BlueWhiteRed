#ifndef __LIST_NODE_H_
#define __LIST_NODE_H_

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class List {
public:
    List() {
        head = new ListNode;
        head->next = nullptr;
    }

    void createList(const std::vector<int> &nums, const int &type);
    void insertList(const int &data);
    void travelList();
    int addNode();
    void deleteData(int &addNum);
    bool ifClear();
    void clearList();
    ListNode* getListHead() { return head->next; }
    void setListHead(ListNode *node) { head->next = node; }

private:
    ListNode *head;     // 头指针
    int num;            // 链表元素的个数
};

// 头插法
inline void List::insertList(const int &data) {
    ListNode *cur = new ListNode(data, head->next);
    head->next = cur;
}

/*
nums: vector stored data to insert.
type: 0: insert from head, 1: insert from tail
*/
inline void List::createList(const std::vector<int> &nums, const int &type = 1) {
    if (0 == type) {
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            insertList(*it);
        }
    } else if (1 == type) {
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            insertList(*it);
        }
    }

}

inline void List::travelList() {
    ListNode *temp = head->next;    // 防止头指针地址改变
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next; 
    }
    std::cout << std::endl;
}

inline void List::deleteData(int &index) {
    int i, j = 0;
    ListNode *tp = nullptr;
    ListNode *link = head;  // link为删除节点后面的一个节点，temp为删除节点

    if (index > num || index < 0) {
        std::cout << "the index of node to delete is error!" << std::endl;
    } else {
        while (link->next) {
            tp = link->next;    // 第一个节点
            ++j;
            if (i == j) {
                link->next = tp->next;
                delete tp;
                break;
            }
            link = link->next;
        }
    }
}

inline bool List::ifClear() {
    if (!head->next) {
        return true;
    }
    return false;
}

inline void List::clearList() {
    ListNode *tp = nullptr;
    ListNode *ph = head->next;

    while (head->next) {
        tp = ph;
        ph = ph->next;
        delete tp;
        head->next = ph;
    }
}

#endif