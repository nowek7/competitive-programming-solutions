#include <algorithm>

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

int maxDiffOfSubTree(TreeNode* root, int minVal, int maxVal)
{
  if (!root) {
    return maxVal - minVal;
  }

  minVal = std::min(minVal, root->val);
  maxVal = std::max(maxVal, root->val);

  const int leftDiff = maxDiffOfSubTree(root->left, minVal, maxVal);
  const int rightDiff = maxDiffOfSubTree(root->right, minVal, maxVal);

  return std::max(leftDiff, rightDiff);
}

int maxAncestorDiff(TreeNode* root)
{
  return maxDiffOfSubTree(root, root->val, root->val);
}

int main()
{
  // 1026. Maximum Difference Between Node and Ancestor

  return 0;
}
