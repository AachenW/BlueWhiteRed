#ifndef __BINARY_ORDINARY_TREE_H_
#define __BINARY_ORDINARY_TREE_H_

#include <iostream>
#include <string>
#include <vector>
#include <queue>

namespace binary_ordinary_tree {
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BinaryTree {
public:
	BinaryTree() = default;
	~BinaryTree() { DeleteTree(root); }

	int InitTreeFromVec(const std::vector<std::string> &vec);
	void DeleteTree(TreeNode *root);
	TreeNode *GetRoot() const { return this->root; };
    void SetRoot(TreeNode *root) { this->root = root; }
	void LevelTraversal() const;

protected:
	void LevelTraversal(TreeNode *pNode) const;
private:
	TreeNode *root{nullptr};
};

void BinaryTree::LevelTraversal() const {
	TreeNode *node = root;
	LevelTraversal(node);
	return;
}

void BinaryTree::LevelTraversal(TreeNode *root) const {
    std::deque<TreeNode*> Q;
    Q.emplace_back(root);
    TreeNode *node;
    while (!Q.empty()) {
        node = Q.front();
        Q.pop_front();
        std::cout << node->val << " ";

        if (nullptr != node->left) {
            Q.emplace_back(node->left);
        }
        if (nullptr != node->right) {
            Q.emplace_back(node->right);
        }
    }
}

void BinaryTree::DeleteTree(TreeNode *root) {
    if (root) {
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

int BinaryTree::InitTreeFromVec(const std::vector<std::string>& vec)
{
	std::deque<TreeNode*> queue;
	root = new TreeNode(atoi(vec[0].c_str()));
	int i = 1;
	queue.emplace_back(root);
	while (!queue.empty())
	{
		int len = queue.size();
		while (len--)
		{
			TreeNode* node = queue.front();
			queue.pop_back();
			if (vec[i] != "null")
			{
				node->left = new TreeNode(atoi(vec[i].c_str()));
				queue.emplace_back(node->left);
			}
			i++;
			if (i == vec.size())
				// 插入完毕，成功返回
				return 1;
			if (vec[i] != "null")
			{
				node->right = new TreeNode(atoi(vec[i].c_str()));
				queue.emplace_back(node->right);
			}
			i++;
			if (i == vec.size())
				return 1;
		}
	}
	return 0;
}
}

#endif