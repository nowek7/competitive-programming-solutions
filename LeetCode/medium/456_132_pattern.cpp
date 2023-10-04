#include <climits>
#include <iostream>
#include <stack>
#include <vector>

bool find132pattern(std::vector<int>& nums)
{
  // Brute force
  for (int i = 0; i < nums.size() - 2; ++i) {
    for (int j = i + 1; j < nums.size() - 1; ++j) {
      for (int k = j + 1; k < nums.size(); ++k) {
        if (nums[i] < nums[k] && nums[j] > nums[k]) {
          return true;
        }
      }
    }
  }
  return false;
}

bool find132pattern_v2(std::vector<int>& nums)
{
  if (nums.size() < 3) {
    return false;
  }

  int thirdNum = INT_MIN;
  std::stack<int> pattern;
  for (int i = nums.size() - 1; i >= 0; --i) {
    if (nums[i] < thirdNum) {
      return true;
    }

    while (!pattern.empty() && pattern.top() < nums[i]) {
      thirdNum = pattern.top();
      pattern.pop();
    }

    pattern.push(nums[i]);
  }

  return false;
}

int main()
{
  // 456. 132 Pattern
  {
    std::vector<int> nums = {1, 2, 3, 4};
    std::cout << find132pattern(nums) << '\n';
  }
  std::cout << "------------" << '\n';
  {
    std::vector<int> nums = {3, 1, 4, 2};
    std::cout << find132pattern(nums) << '\n';
  }
  std::cout << "------------" << '\n';
  {
    std::vector<int> nums = {-1, 3, 2, 0};
    std::cout << find132pattern(nums) << '\n';
  }
  std::cout << "------------" << '\n';
  {
    std::vector<int> nums = {1, 0, 1, -4, -3};
    std::cout << find132pattern(nums) << '\n';
  }

  std::cout << "------------" << '\n';
  {
    std::vector<int> nums = {3, 5, 0, 3, 4};
    std::cout << find132pattern_v2(nums) << '\n';
  }

  return 0;
}