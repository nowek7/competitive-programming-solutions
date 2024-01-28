#include <vector>

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode():
    val(0),
    left(nullptr),
    right(nullptr)
  {
  }

  TreeNode(int x):
    val(x),
    left(nullptr),
    right(nullptr)
  {
  }

  TreeNode(int x, TreeNode* left, TreeNode* right):
    val(x),
    left(left),
    right(right)
  {
  }
};

void insertLeaf(std::vector<int>& leaf, TreeNode* root)
{
  if (!root) {
    return;
  }

  if (root->left) {
    insertLeaf(leaf, root->left);
  }
  if (root->right) {
    insertLeaf(leaf, root->right);
  }
  if (!root->left && !root->right) {
    leaf.emplace_back(root->val);
  }
}

bool leafSimilar(TreeNode* root1, TreeNode* root2)
{
  std::vector<int> leaf1;
  std::vector<int> leaf2;

  insertLeaf(leaf1, root1);
  insertLeaf(leaf2, root2);

  return leaf1 == leaf2;
}

int main()
{
  // 94. Binary Tree Inorder Traversal

  return 0;
}
