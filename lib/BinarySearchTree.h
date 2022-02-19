#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#include <vector>
#include <iostream>
#include <deque>

typedef int TreeDataType;

namespace binary_search_tree {
struct TreeNode{
    TreeDataType val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinarySearchTree{
public:
    BinarySearchTree() = default;
    BinarySearchTree(TreeDataType val);
    ~BinarySearchTree() { DeleteTree(root); std::cout << "BST has been deleted ..." << std::endl; };

public:
    int InitTree(const std::vector<TreeDataType> &nums);
    int Insert(const TreeDataType &val);
    int Traversal(int type) const;

    TreeNode *GetRoot() const { return this->root; };
    void SetRoot(TreeNode *root) { this->root = root; }
//    TreeNode* Search(TreeNode *pNode, TreeDataType val);

protected:
    void Insert(TreeNode *pNode, const TreeDataType &val);
    void PreorderTraversal(const TreeNode *pNode) const;
    void InorderTraversal(const TreeNode *pNode) const;
    void PosorderTraversal(const TreeNode *pNode) const;
    void PreorderTraversal(const TreeNode *pNode, int type) const;
    void InorderTraversal(const TreeNode *pNode, int type) const;
    void PosorderTraversal(const TreeNode *pNode, int type) const;
    void LevelTraversal(const TreeNode *pNode) const;
    void LevelTraversal(const TreeNode *pNode, int level) const;
    int GetMaxDepth() const;
    int GetMaxDepth(const TreeNode *pNode) const;

    void PrintNode(TreeNode *pNode);
    void DeleteTree(TreeNode *pNode);

private:
    TreeNode *root{nullptr};
    bool flag;
};
}

#endif