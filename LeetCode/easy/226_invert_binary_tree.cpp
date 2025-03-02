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

void invert(TreeNode* root)
{
  if (!root) {
    return;
  }

  TreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;

  invert(root->left);
  invert(root->right);
}

TreeNode* invertTree(TreeNode* root)
{
  invert(root);
  return root;
}

int main()
{
  // 226. Invert Binary Tree

  return 0;
}
