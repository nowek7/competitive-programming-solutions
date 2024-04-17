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
    void addRow(TreeNode* root, int currDepth, int val, int depth)
    {
        if (root) {
            if (currDepth + 1 == depth) {
                root->left = new TreeNode(val, root->left, nullptr);
                root->right = new TreeNode(val, nullptr, root->right);
            } else {
                addRow(root->left, currDepth + 1, val, depth);
                addRow(root->right, currDepth + 1, val, depth);
            }
        } 
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        } 

        addRow(root, 1, val, depth);

        return root;
    }
};

int main()
{
    // 623. Add One Row to Tree
    
    return 0;
}