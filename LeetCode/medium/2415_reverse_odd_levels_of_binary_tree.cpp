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

void reverseOddLevels(TreeNode* left, TreeNode* right, bool isOdd)
{
  if (!left && !right) {
    return;
  }

  if (isOdd) {
    int tmp = left->val;
    left->val = right->val;
    right->val = tmp;
  }

  reverseOddLevels(left->left, right->right, !isOdd);
  reverseOddLevels(left->right, right->left, !isOdd);
}

TreeNode* reverseOddLevels(TreeNode* root)
{
  reverseOddLevels(root->left, root->right, true);
  return root;
}

int main()
{
  // 2415. Reverse Odd Levels of Binary Tree

  return 0;
}
