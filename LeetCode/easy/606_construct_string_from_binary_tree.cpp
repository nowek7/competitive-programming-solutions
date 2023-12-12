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

std::string leaf2str(TreeNode* node)
{
  std::string lev;
  if (node) {
    lev += "(";
    lev += std::to_string(node->val);
    if (node->right) {
      lev += (node->left) ? leaf2str(node->left) : "()";
      lev += leaf2str(node->right);
    } else {
      lev += leaf2str(node->left);
    }
    lev += ")";
  }
  return lev;
}

std::string tree2str(TreeNode* root)
{
  std::string result = std::to_string(root->val);
  if (root->right) {
    result += (root->left) ? leaf2str(root->left) : "()";
    result += leaf2str(root->right);
  } else {
    result += leaf2str(root->left);
  }
  return result;
}

int main()
{
  // 606. Construct String from Binary Tree

  return 0;
}
