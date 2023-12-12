#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
  std::vector<int> result(2);

  for (std::size_t i = 0; i < nums.size(); ++i) {
    for (std::size_t j = i + 1; j < nums.size(); ++j) {
      if (nums[i] + nums[j] == target) {
        return {static_cast<int>(i), static_cast<int>(j)};
      }
    }
  }

  return result;
}

std::vector<int> twoSum_v2(std::vector<int>& nums, int target)
{
  std::unordered_map<int, int> traversed;

  for (std::size_t i = 0; i < nums.size(); ++i) {
    const int x = target - nums[i];
    if (traversed.find(x) != traversed.end()) {
      return {static_cast<int>(i), traversed[x]};
    }

    traversed[nums[i]] = i;
  }

  return {-1, -1};
}

int main()
{
  // 1. Two Sum
  {
    std::vector<int> nums = {2, 7, 11, 15};
    const int target = 9;

    auto results = twoSum(nums, target);
    std::cout << results[0] << " " << results[1] << '\n';
  }

  {
    std::vector<int> nums = {3, 2, 4};
    const int target = 6;

    auto results = twoSum_v2(nums, target);
    std::cout << results[0] << " " << results[1] << '\n';
  }

  {
    std::vector<int> nums = {3, 3};
    const int target = 6;

    auto results = twoSum(nums, target);
    std::cout << results[0] << " " << results[1] << '\n';
  }

  return 0;
}
