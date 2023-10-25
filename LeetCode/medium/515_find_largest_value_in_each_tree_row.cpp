#include <climits>
#include <cmath>
#include <queue>
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

std::vector<int> largestValues(TreeNode* root)
{
  std::vector<int> result;
  if (!root) {
    return result;
  }

  std::queue<TreeNode*> levelNodes;
  levelNodes.push(root);
  while (!levelNodes.empty()) {
    int maxInLevel = INT_MIN;
    const int currentLevelSize = levelNodes.size();
    for (int i = 0; i < currentLevelSize; ++i) {
      TreeNode* node = levelNodes.front();
      levelNodes.pop();

      maxInLevel = std::max(maxInLevel, node->val);
      if (node->left) {
        levelNodes.push(node->left);
      }
      if (node->right) {
        levelNodes.push(node->right);
      }
    }
    result.push_back(maxInLevel);
  }

  return result;
}

int main()
{
  // 515. Find Largest Value in Each Tree Row

  return 0;
}