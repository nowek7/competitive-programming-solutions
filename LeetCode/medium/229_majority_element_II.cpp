#include <algorithm>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

std::vector<int> majorityElement(std::vector<int>& nums)
{
  const int threshold = nums.size() / 3;
  if (nums.size() < threshold) {
    return nums;
  }

  std::unordered_map<int, int> frequencies;
  for (int i = 0; i < nums.size(); ++i) {
    ++frequencies[nums[i]];
  }

  std::vector<int> result;
  for (auto& [number, value]: frequencies) {
    if (value > threshold) {
      result.push_back(number);
    }
  }

  return result;
}

std::vector<int> getRandNums(int size)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> uid(0, 4);

  std::vector<int> nums;
  nums.reserve(size);

  for (int i = 0; i < size; ++i) {
    nums.push_back(uid(gen));
  }

  return nums;
}

void printResult(const std::vector<int>& nums)
{
  if (!nums.empty()) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      std::cout << nums[i] << " ";
    }
    std::cout << *nums.rbegin() << '\n';
  }
}

int main()
{
  // 229. Majority Element II

  {
    std::vector<int> nums = {3, 2, 3};
    auto result = majorityElement(nums);
    printResult(result);
  }

  {
    std::vector<int> nums = {1};
    auto result = majorityElement(nums);
    printResult(result);
  }

  {
    std::vector<int> nums = {1, 2};
    auto result = majorityElement(nums);
    printResult(result);
  }

  {
    std::vector<int> nums = getRandNums(5);
    auto result = majorityElement(nums);
    printResult(result);
  }
}
