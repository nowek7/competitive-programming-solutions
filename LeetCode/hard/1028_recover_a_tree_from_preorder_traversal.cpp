#include <string>

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

class Solution
{
public:
  TreeNode* recoverFromPreorder(std::string traversal)
  {
    int idx = 0;
    return dfs(traversal, idx, 0);
  }

private:
  TreeNode* dfs(const std::string& traversal, int& idx, int depth)
  {
    if (idx >= traversal.size()) {
      return nullptr;
    }

    int count = 0;
    while (idx + count < traversal.size() && traversal[idx + count] == '-') {
      ++count;
    }

    if (count != depth) {
      return nullptr;
    }

    idx += count;

    int value = 0;
    while (idx < traversal.size() && std::isdigit(traversal[idx])) {
      value = (value * 10) + (traversal[idx] - '0');
      ++idx;
    }

    TreeNode* node = new TreeNode(value);
    node->left = dfs(traversal, idx, depth + 1);
    node->right = dfs(traversal, idx, depth + 1);

    return node;
  }
};

int main()
{
  // 1028. Recover a Tree From Preorder Traversal

  return 0;
}
