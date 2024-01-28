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

class Solution
{
private:
  int m_low {};
  int m_high {};

public:
  void leaf(int& currentSum, TreeNode* root)
  {
    if (root) {
      if (root->val >= m_low && root->val <= m_high) {
        currentSum += root->val;
      }
      if (root->val >= m_low) {
        leaf(currentSum, root->left);
      }
      if (root->val <= m_high) {
        leaf(currentSum, root->right);
      }
    }
  }

  int rangeSumBST(TreeNode* root, int low, int high)
  {
    m_low = low;
    m_high = high;
    int sum = 0;
    leaf(sum, root);
    return sum;
  }
};

int main()
{
  // 94. Binary Tree Inorder Traversal

  return 0;
}
