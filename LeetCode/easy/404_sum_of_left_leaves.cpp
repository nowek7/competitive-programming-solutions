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
  void sumLeft(TreeNode* node, bool isLeft, int& currentSum)
  {
    if (node) {
      if (node->left || node->right) {
        sumLeft(node->left, true, currentSum);
        sumLeft(node->right, false, currentSum);
      } else if (isLeft) {
        currentSum += node->val;
      }
    }
  }

  int sumOfLeftLeaves(TreeNode* root)
  {
    int sum = 0;
    sumLeft(root, false, sum);
    return sum;
  }
};

int main()
{
  // 404. Sum of Left Leaves

  return 0;
}
