#include <cmath>

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

int part(TreeNode* root, int& prev)
{
  if (!root) {
    return 0;
  }

  int left = part(root->left, prev);
  int right = part(root->right, prev);
  prev = std::max(prev, left + right);

  return std::max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
  int curr = 0;
  part(root, curr);
  return curr;
}

int main()
{
  // 543. Diameter of Binary Tree

  return 0;
}
