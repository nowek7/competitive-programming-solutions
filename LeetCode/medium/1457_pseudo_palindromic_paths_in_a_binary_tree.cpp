#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>

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

bool isOneOddParityOfNumber(std::array<int, 9>& nums)
{
  return std::count_if(
           nums.begin(),
           nums.end(),
           [](auto number) {
             return number & 1;
           }
         )
    <= 1;
}

void print(std::array<int, 9>& nums)
{
  for (int i = 0; i < nums.size() - 1; ++i) {
    if (nums[i] > 0) {
      std::cout << "(" << (i + 1) << "," << nums[i] << ")"
                << " ";
    }
  }
  if (nums.back() > 0) {
    std::cout << "(9," << nums.back() << ")";
  }
  std::cout << '\n';
}

void solve(TreeNode* root, int& result, std::array<int, 9>& frequency)
{
  if (root) {
    ++frequency[root->val - 1];

    if (!root->left && !root->right) {
      if (isOneOddParityOfNumber(frequency)) {
        ++result;
      }
    }

    if (root->left) {
      solve(root->left, result, frequency);
    }

    if (root->right) {
      solve(root->right, result, frequency);
    }

    --frequency[root->val - 1];
  }
}

int pseudoPalindromicPaths(TreeNode* root)
{
  if (!root->left && !root->right) {
    return 1;
  }

  int result = 0;
  std::array<int, 9> frequency {0};
  solve(root, result, frequency);
  return result;
}

int main()
{
  // 1457. Pseudo-Palindromic Paths in a Binary Tree

  return 0;
}
