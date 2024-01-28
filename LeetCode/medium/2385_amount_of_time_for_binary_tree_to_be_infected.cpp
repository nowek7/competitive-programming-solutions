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

int walkThroughNodes(TreeNode* root, int& start, int& maxDistance)
{
  int depth = 0;
  if (!root) {
    return depth;
  }

  int leftDepth = walkThroughNodes(root->left, start, maxDistance);
  int rightDepth = walkThroughNodes(root->right, start, maxDistance);

  if (root->val == start) {
    maxDistance = std::max(leftDepth, rightDepth);
    depth = -1;
  } else if (leftDepth >= 0 && rightDepth >= 0) {
    depth = std::max(leftDepth, rightDepth) + 1;
  } else {
    int distance = std::abs(leftDepth) + std::abs(rightDepth);
    maxDistance = std::max(maxDistance, distance);
    depth = std::min(leftDepth, rightDepth) - 1;
  }
  return depth;
}

int amountOfTime(TreeNode* root, int start)
{
  int maxDistance = 0;
  walkThroughNodes(root, start, maxDistance);

  return maxDistance;
}

int main()
{
  // 2385. Amount of Time for Binary Tree to Be Infected

  return 0;
}
