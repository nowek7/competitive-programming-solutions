#include <string>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    void addCharFromLeaf(TreeNode* root, std::string &smallestStr, std::string pathStr = "")
    {
        if (!root) {
            return;
        }

        pathStr = std::string(1, root->val + 97) + pathStr;
        if (!root->left && !root->right) {
            smallestStr = smallestStr.empty() ? pathStr: std::min(smallestStr, pathStr);
        }

        addCharFromLeaf(root->left, smallestStr, pathStr);
        addCharFromLeaf(root->right, smallestStr, pathStr);
    }

    std::string smallestFromLeaf(TreeNode* root) {
        std::string smallestStr;
        addCharFromLeaf(root, smallestStr);
        return smallestStr;
    }
};

int main()
{
    // 988. Smallest String Starting From Leaf

    return 0;
}
