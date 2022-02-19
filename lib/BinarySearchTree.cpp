#include "BinarySearchTree.h"


namespace binary_search_tree {

int BinarySearchTree::InitTree(const std::vector<TreeDataType> &nums) {
    for (const auto &num : nums) {
        Insert(num);
    }
    return 0;
}

int BinarySearchTree::Insert(const TreeDataType &val) {
    flag = true;
    if (root) {
        Insert(root, val);
    } else {
        root = new TreeNode(val);
        root->left = nullptr;
        root->right = nullptr;
    }
    return (int) flag;
}

void BinarySearchTree::Insert(TreeNode *pNode, const TreeDataType &val) {
    if (nullptr == pNode) {
        return;
    }
    if (pNode->val < val) {
        if (pNode->right) {
            Insert(pNode->right, val);
        } else {
            pNode->right = new TreeNode;
            pNode->right->val = val;
            pNode->right->left = nullptr;
            pNode->right->right = nullptr;
        }
    } else {
        if (pNode->left) {
            Insert(pNode->left, val);
        } else {
            pNode->left = new TreeNode;
            pNode->left->val = val;
            pNode->left->left = nullptr;
            pNode->left->right = nullptr;
        }
    }
}

int BinarySearchTree::Traversal(int type) const {
    if (!root) {
        return -1;
    }

    const TreeNode *treeRoot = root;
    if (0 == type) {
        PreorderTraversal(treeRoot);
    } else if (1 == type) {
        InorderTraversal(treeRoot);
    } else if (2 == type) {
        PosorderTraversal(treeRoot);
    } else if (3 == type) {
        LevelTraversal(treeRoot);
    } else {
        return -1;
    }
    return 0;
}

// Recursion version
void BinarySearchTree::PreorderTraversal(const TreeNode* root) const {
    if (root) {
        std::cout << root->val << " ";
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

// Nonrecursion version
void BinarySearchTree::PreorderTraversal(const TreeNode* root, int type) const {
    std::deque<std::pair<TreeNode*, bool>> stack;
    TreeNode *cur = const_cast<TreeNode*>(root);
    stack.emplace_back(std::make_pair(cur, false));
    bool visited;
    while (!stack.empty()) {
        root = stack.back().first;
        visited = stack.back().second;
        stack.pop_back();
        if (nullptr == root) {
            continue;
        }
        if (visited) {
            std::cout << root->val << " ";
        } else {
            stack.emplace_back(std::make_pair(root->right, false));
            stack.emplace_back(std::make_pair(root->left, false));
            stack.emplace_back(std::make_pair(root, true));
        }
    }
}

// // Simple nonrecursion version of pre-order traverse
// void BinarySearchTree::PreorderTraversal_Sample(const TreeNode* root, int type) const {
//     std::deque<TreeNode*> stack;
//     TreeNode *cur = const_cast<TreeNode*>(root);
//     while (nullptr != cur || !stack.empty()) {
//         while (nullptr != cur) {
//             stack.emplace_back(cur);
//             std::cout << cur->val << " ";
//             cur = cur->left;
//         }
//         if (!stack.empty()) {
//             cur = stack.back();
//             stack.pop_back();
//             cur = cur->right;
//         }
//     }
// }

// Simple nonrecursion version of pre-order traverse
// void BinarySearchTree::PreorderTraversal_Sample(const TreeNode* root, int type) const {
//     std::deque<TreeNode*> stack;
//     TreeNode *cur = const_cast<TreeNode*>(root);
//     stack.emplace_back(cur);
//     bool visited;
//     while (!stack.empty()) {
//         cur = stack.back();
//         stack.pop_back();
//         if (nullptr == root) {
//             continue;
//         }
//         else {
//             std::cout << cur->val << " ";
//             stack.emplace_back(root->right);
//             stack.emplace_back(root->left);
//         }
//     }
// }

// Recursion version
void BinarySearchTree::InorderTraversal(const TreeNode *root) const {
    if (root) {
        InorderTraversal(root->left);
        std::cout << root->val << " ";
        InorderTraversal(root->right);
    }
}

// Nonrecursion version
void BinarySearchTree::InorderTraversal(const TreeNode* root, int type) const {
    std::deque<std::pair<TreeNode*, bool>> stack;
    TreeNode *cur = const_cast<TreeNode*>(root);
    stack.emplace_back(std::make_pair(root, false));
    bool visited;
    while (!stack.empty()) {
        root = stack.back().first;
        visited = stack.back().second;
        if (nullptr == root) {
            continue;
        }
        if (visited) {
            std::cout << root->val << " ";
        } else {
            stack.emplace_back(std::make_pair(root->right, false));
            stack.emplace_back(std::make_pair(root, true));
            stack.emplace_back(std::make_pair(root->left, false));
        }
    }
}

// // Simple nonrecursion version of in-order traverse
// void BinarySearchTree::InorderTraversal(const TreeNode* root, int type) const {
//     std::deque<TreeNode*> stack;
//     TreeNode *cur = const_cast<TreeNode*>(root);
//     while (nullptr != cur || !stack.empty()) {
//         while (nullptr != cur) {
//             stack.emplace_back(cur);
//             cur = cur->left;
//         }
//         if (!stack.empty()) {
//             cur = stack.back();
//             std::cout << cur->val << " ";
//             stack.pop_back();
//             cur = cur->right;
//         }
//     }
// }

// Recursion version
void BinarySearchTree::PosorderTraversal(const TreeNode *root) const {
    if (root) {
        PosorderTraversal(root->left);
        PosorderTraversal(root->right);
        std::cout << root->val << " ";
    }
}

// Nonrecursion version
void BinarySearchTree::PosorderTraversal(const TreeNode* root, int type) const {
    std::deque<std::pair<TreeNode*, bool>> stack;
    TreeNode *cur = const_cast<TreeNode*>(root);
    stack.emplace_back(std::make_pair(root, false));
    bool visited;
    while (!stack.empty()) {
        root = stack.back().first;
        visited = stack.back().second;
        stack.pop_back();
        if (nullptr == root) {
            continue;
        }
        if (visited) {
            std::cout << root->val << " ";
        } else {
            stack.emplace_back(std::make_pair(root, true));
            stack.emplace_back(std::make_pair(root->right, false));
            stack.emplace_back(std::make_pair(root->left, false));
        }
    }
}

void BinarySearchTree::LevelTraversal(const TreeNode *root) const {
    int h = GetMaxDepth();
    for (int i = 1; i <= h; ++h) {
        LevelTraversal(root, i);
    }
}

void BinarySearchTree::LevelTraversal(const TreeNode *root, int level) const {
    if (!root) {
        return ;
    }
    if (0 == level) {
        std::cout << root->val << " ";
    } else if (level > 0) {
        LevelTraversal(root->left, level - 1);
        LevelTraversal(root->right, level - 1);
    }
}

void BinarySearchTree::DeleteTree(TreeNode *root) {
    if (root) {
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

int BinarySearchTree::GetMaxDepth() const {
    const TreeNode *node = root;
    return GetMaxDepth(node);
}

int BinarySearchTree::GetMaxDepth(const TreeNode *pNode) const {
    if (!pNode) {
        return 0;
    }

    int leftDepth = GetMaxDepth(pNode->left);
    int rightDepth = GetMaxDepth(pNode->right);

    return std::max(leftDepth, rightDepth) + 1;
}
}