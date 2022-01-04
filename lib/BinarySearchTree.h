#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#include <vector>
#include <iostream>

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
    ~BinarySearchTree() { DeleteTree(root); };

public:
    int InitTree(const std::vector<TreeDataType> &nums);
    int Insert(const TreeDataType &val);
    int Traversal(int type) const;

//    TreeNode* Search(TreeNode *pNode, TreeDataType val);

protected:
    void Insert(TreeNode *pNode, const TreeDataType &val);
    void PreorderTraversal(const TreeNode *pNode) const;
    void InorderTraversal(const TreeNode *pNode) const;
    void PosorderTraversal(const TreeNode *pNode) const;
    void LevelTraversal(const TreeNode *pNode) const;
    void LevelTraversal(const TreeNode *pNode, int level) const;
    int GetMaxDepth() const;
    int GetMaxDepth(const TreeNode *pNode) const;

    void PrintNode(TreeNode *pNode);
    void DeleteTree(TreeNode *pNode);

private:
    TreeNode *root;
    bool flag;
};
}

#endif