#include <unordered_set>

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

class FindElements
{
public:
  FindElements(TreeNode* root)
  {
    if (root) {
      root->val = 0;
      m_store.insert(root->val);
      recover(root);
    }
  }

  bool find(int target)
  {
    return m_store.find(target) != m_store.end();
  }

private:
  void recover(TreeNode* node)
  {
    if (!node) {
      return;
    }

    if (node->left) {
      node->left->val = 2 * node->val + 1;
      m_store.insert(node->left->val);
      recover(node->left);
    }

    if (node->right) {
      node->right->val = 2 * node->val + 2;
      m_store.insert(node->right->val);
      recover(node->right);
    }
  }

  std::unordered_set<int> m_store;
};

int main()
{
  // 1261. Find Elements in a Contaminated Binary Tree

  return 0;
}
