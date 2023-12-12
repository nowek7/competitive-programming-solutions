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

void solve(TreeNode* node, std::vector<int>& container)
{
  if (node) {
    solve(node->left, container);
    container.push_back(node->val);
    solve(node->right, container);
  }
}

std::vector<int> inorderTraversal(TreeNode* root)
{
  std::vector<int> result;
  solve(root, result);
  return result;
}

int main()
{
  // 94. Binary Tree Inorder Traversal

  return 0;
}
