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
public:
  TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder)
  {
    const int numOfNodes = preorder.size();
    std::vector<int> indexInPostorder(numOfNodes + 1);
    for (int index = 0; index < numOfNodes; index++) {
      indexInPostorder[postorder[index]] = index;
    }

    return constructTree(0, numOfNodes - 1, 0, preorder, indexInPostorder);
  }

private:
  TreeNode*
  constructTree(int preStart, int preEnd, int postStart, std::vector<int>& preorder, std::vector<int>& indexInPostorder)
  {
    if (preStart > preEnd) {
      return nullptr;
    }

    if (preStart == preEnd) {
      return new TreeNode(preorder[preStart]);
    }

    int leftRoot = preorder[preStart + 1];
    int numOfNodesInLeft = indexInPostorder[leftRoot] - postStart + 1;

    TreeNode* root = new TreeNode(preorder[preStart]);
    root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft, postStart, preorder, indexInPostorder);

    root->right =
      constructTree(preStart + numOfNodesInLeft + 1, preEnd, postStart + numOfNodesInLeft, preorder, indexInPostorder);

    return root;
  }
};

int main()
{
  // 889. Construct Binary Tree from Preorder and Postorder Traversal

  return 0;
}
