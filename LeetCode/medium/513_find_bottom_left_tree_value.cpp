#include <queue>

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

int findBottomLeftValue(TreeNode* root)
{
  int leftValue = root->val;

  std::queue<TreeNode*> line;
  line.push(root);
  while (!line.empty()) {
    const int length = line.size();
    for (int i = 0; i < length; ++i) {
      TreeNode* node = line.front();
      line.pop();

      if (i == 0) {
        leftValue = node->val;
      }
      if (node->left) {
        line.push(node->left);
      }
      if (node->right) {
        line.push(node->right);
      }
    }
  }

  return leftValue;
}

int main()
{
  // 513. Find Bottom Left Tree Value

  return 0;
}
