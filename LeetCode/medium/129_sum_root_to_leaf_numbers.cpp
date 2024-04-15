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
  int sumLeaves(TreeNode* root, int& sum)
  {
    if (root) {
      if (root->left || root->right) {
        int current = 10 * (root->val + sum);
        const int left = sumLeaves(root->left, current);
        const int right = sumLeaves(root->right, current);
        return left + right;
      } else {
        return sum + root->val;
      }
    } else {
      return 0;
    }
  }

  int sumNumbers(TreeNode* root)
  {
    int sum = 0;
    return sumLeaves(root, sum);
  }
};

int main()
{
  // 129. Sum Root to Leaf Numbers

  return 0;
}
