#include <cassert>
#include <numeric>
#include <unordered_set>
#include <vector>

std::vector<int> findErrorNums(std::vector<int>& nums)
{
  std::unordered_set<int> uniqueNums(nums.begin(), nums.end());

  const int sum = (1 + nums.size()) * 0.5 * nums.size();
  const int currentSum = std::accumulate(nums.begin(), nums.end(), 0);
  const int uniqueSum = std::accumulate(uniqueNums.begin(), uniqueNums.end(), 0);

  return {currentSum - uniqueSum, sum - uniqueSum};
}

std::vector<int> findErrorNums_v2(std::vector<int>& nums)
{
  std::vector<bool> visible(nums.size(), false);

  std::vector<int> result(2, 0);
  for (int i = 0; i < nums.size(); ++i) {
    if (visible[nums[i] - 1]) {
      result[0] = nums[i];
    } else {
      visible[nums[i] - 1] = true;
    }
  }

  for (int i = 0; i < nums.size(); ++i) {
    if (!visible[i]) {
      result[1] = i + 1;
    }
  }

  return result;
}

int main()
{
  // 645. Set Mismatch

  {
    std::vector<int> nums = {1, 2, 2, 4};
    std::vector<int> expected = {2, 3};
    std::vector<int> result = findErrorNums(nums);
    result = findErrorNums_v2(nums);
    assert(result == expected);
  }

  {
    std::vector<int> nums = {1, 1};
    std::vector<int> expected = {1, 2};
    std::vector<int> result = findErrorNums(nums);
    assert(result == expected);
    result = findErrorNums_v2(nums);
    assert(result == expected);
  }

  return 0;
}
