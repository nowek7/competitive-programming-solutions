#include <iostream>
#include <unordered_map>
#include <vector>

int numIdenticalPairs(std::vector<int>& nums)
{
  std::unordered_map<int, int> indexesByValue;
  for (int i = 0; i < nums.size(); ++i) {
    indexesByValue[nums[i]]++;
  }

  int sum = 0;
  for (auto [value, count]: indexesByValue) {
    if (count > 1) {
      sum += 0.5 * (count - 1) * count;
    }
  }

  return sum;
}

int main()
{
  // 1512. Number of Good Pairs
  {
    std::vector<int> nums = {1, 2, 3, 1, 1, 3};
    std::cout << numIdenticalPairs(nums) << '\n';
  }

  {
    std::vector<int> nums = {1, 1, 1, 1};
    std::cout << numIdenticalPairs(nums) << '\n';
  }

  {
    std::vector<int> nums = {1, 2, 3};
    std::cout << numIdenticalPairs(nums) << '\n';
  }

  return 0;
}