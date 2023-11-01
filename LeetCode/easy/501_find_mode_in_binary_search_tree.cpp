#include <cmath>
#include <unordered_map>
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

void gatherValues(TreeNode* root, std::vector<int>& collection)
{
  if (root) {
    collection.push_back(root->val);
    gatherValues(root->left, collection);
    gatherValues(root->right, collection);
  }
}

std::vector<int> findMode(TreeNode* root)
{
  std::vector<int> elements;
  if (!root) {
    return elements;
  }
  gatherValues(root, elements);

  int maxFrequency = 0;
  std::unordered_map<int, int> frequencies;
  for (auto elem: elements) {
    ++frequencies[elem];
    maxFrequency = std::max(maxFrequency, frequencies[elem]);
  }

  std::vector<int> result;
  for (auto [value, freq]: frequencies) {
    if (freq == maxFrequency) {
      result.emplace_back(value);
    }
  }

  return result;
}

int main()
{
  // 501. Find Mode in Binary Search Tree

  return 0;
}
