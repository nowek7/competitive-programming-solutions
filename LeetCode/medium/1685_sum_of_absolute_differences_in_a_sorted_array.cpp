#include <iostream>
#include <vector>

void printNums(const std::vector<int>& nums)
{
  if (!nums.empty()) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      std::cout << nums[i] << " ";
    }
    std::cout << nums.back() << '\n';
  }
}

std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums)
{
  const int len = nums.size();
  std::vector<int> prefixSums(len + 1, 0);
  std::vector<int> suffixSums(len + 1, 0);
  for (int i = 0, j = len - 1; i < len && j >= 0; ++i, --j) {
    prefixSums[i + 1] = prefixSums[i] + nums[i];
    suffixSums[j] = suffixSums[j + 1] + nums[j];
  }

  std::vector<int> result(len);
  for (int i = 0; i < len; ++i) {
    result[i] = (nums[i] * i) - prefixSums[i] + suffixSums[i + 1] + (-nums[i] * (nums.size() - 1 - i));
  }

  return result;
}

std::vector<int> getSumAbsoluteDifferences_v2(std::vector<int>& nums)
{
  const int len = nums.size();
  std::vector<int> prefixSums(len + 1, 0);
  for (int i = 0; i < len; ++i) {
    prefixSums[i + 1] = prefixSums[i] + nums[i];
  }

  std::vector<int> result(len);
  for (int i = 0; i < len; ++i) {
    // result[i] = (nums[i] * i) - prefixSums[i] + suffixSums[i + 1] + (-nums[i] * (nums.size() - 1 - i));
  }

  return result;
}

int main()
{
  // 1685. Sum of Absolute Differences in a Sorted Array

  {
    std::vector<int> nums = {2, 3, 5}; // 4, 3, 5
    std::vector<int> result = getSumAbsoluteDifferences(nums);
    printNums(result);
  }

  {
    std::vector<int> nums = {1, 4, 6, 8, 10}; // 24,15,13,15,21
    std::vector<int> result = getSumAbsoluteDifferences(nums);
    printNums(result);
  }

  return 0;
}
