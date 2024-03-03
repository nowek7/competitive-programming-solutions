
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

bool equal(TreeNode* p, TreeNode* q)
{
  if (!p && !q) {
    return true;
  }

  if (p && q) {
    int leftValue = p->val;
    int rightValue = q->val;

    if (leftValue == rightValue) {
      return equal(p->left, q->left) && equal(p->right, q->right);
    } else {
      return false;
    }
  }
  return false;
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
  return equal(p, q);
}

int main()
{
  // 100. Same Tree

  return 0;
}
