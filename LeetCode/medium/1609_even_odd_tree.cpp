#include <algorithm>
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

bool isEvenOddTree(TreeNode* root)
{
  bool isEvenIdx = true;
  auto isOrdered = [&isEvenIdx](std::vector<int>& values) {
    if (isEvenIdx) {
      return std::adjacent_find(values.begin(), values.end(), std::greater_equal<int>());
    } else {
      return std::adjacent_find(values.begin(), values.end(), std::less_equal<int>());
    }
  };

  std::queue<TreeNode*> line;
  line.push(root);

  while (!line.empty()) {
    const int length = line.size();
    std::vector<int> values(length);
    for (int i = 0; i < length; ++i) {
      TreeNode* node = line.front();
      line.pop();

      if (node->val % 2 == static_cast<int>(isEvenIdx)) {
        values[i] = node->val;
      } else {
        return false;
      }

      if (node->left) {
        line.push(node->left);
      }
      if (node->right) {
        line.push(node->right);
      }
    }

    auto it = isOrdered(values);
    if (it != values.end()) {
      return false;
    }

    isEvenIdx = !isEvenIdx;
  }

  return true;
}

int main()
{
  // 1609. Even Odd Tree

  return 0;
}
