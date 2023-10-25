#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());

  const int target = 0;
  std::set<std::vector<int>> result;
  for (int i = 0; i < nums.size(); ++i) {
    int j = i + 1;
    int k = nums.size() - 1;
    while (j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if (sum == target) {
        result.insert({nums[i], nums[j], nums[k]});
        ++j;
        --k;

        while (j < k && nums[j - 1] == nums[j]) {
          ++j;
        }
        while (j < k && nums[k] == nums[k + 1]) {
          --k;
        }
      } else if (sum < target) {
        ++j;
      } else {
        --k;
      }
    }
  }

  std::vector<std::vector<int>> finalResult(result.begin(), result.end());
  return finalResult;
}

void print(const std::vector<int>& nums)
{
  std::cout << '[';
  if (!nums.empty()) {
    for (auto i = 0; i < nums.size() - 1; ++i) {
      std::cout << nums.at(i) << ',';
    }
    std::cout << *nums.rbegin();
  }
  std::cout << ']';
}

int main()
{
  // 15. 3Sum
  {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    for (auto&& entry: threeSum(nums)) {
      print(entry);
      std::cout << '\n';
    }
  }
  std::cout << '\n';
  {
    std::vector<int> nums = {0, 1, 1};
    for (auto&& entry: threeSum(nums)) {
      print(entry);
      std::cout << '\n';
    }
  }
  std::cout << '\n';
  {
    std::vector<int> nums = {0, 0, 0};
    for (auto&& entry: threeSum(nums)) {
      print(entry);
    }
  }
  std::cout << '\n';
  {
    std::vector<int> nums = {-2, 0, 1, 1, 2};
    for (auto&& entry: threeSum(nums)) {
      print(entry);
    }
  }

  return 0;
}