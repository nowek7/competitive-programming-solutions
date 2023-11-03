#include <utility>

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

std::pair<int, int> traverse(TreeNode* node, int& result)
{
  if (!node) {
    return {0, 0};
  }

  auto [leftSum, leftCount] = traverse(node->left, result);
  auto [rightSum, rightCount] = traverse(node->right, result);

  int sum = node->val + leftSum + rightSum;
  int count = 1 + leftCount + rightCount;

  if ((sum / count) == node->val) {
    ++result;
  }

  return {sum, count};
}

int averageOfSubtree(TreeNode* root)
{
  int result = 0;
  traverse(root, result);
  return result;
}

int main()
{
  return 0;
}
