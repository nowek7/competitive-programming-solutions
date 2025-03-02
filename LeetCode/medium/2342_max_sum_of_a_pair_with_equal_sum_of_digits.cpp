#include <cassert>
#include <unordered_map>
#include <vector>

int sumNumberDigits(int number)
{
  int sum = 0;
  while (number > 9) {
    sum += number % 10;
    number /= 10;
  }
  return sum + number;
};

int maximumSum(std::vector<int>& nums)
{
  int maxSum = -1;
  std::vector<int> digitsSum(9 * 9 + 1, -1);
  for (int i = 0; i < nums.size(); ++i) {
    const int sum = sumNumberDigits(nums[i]);
    if (digitsSum[sum] != -1) {
      maxSum = std::max(maxSum, digitsSum[sum] + nums[i]);
      digitsSum[sum] = std::max(digitsSum[sum], nums[i]);
    } else {
      digitsSum[sum] = nums[i];
    }
  }

  return maxSum;
}

int maximumSum_v2(std::vector<int>& nums)
{
  int maxSum = -1;
  std::vector<int> digitsSum(9 * 9 + 1, -1);
  for (int i = 0; i < nums.size(); ++i) {
    const int sum = sumNumberDigits(nums[i]);
    if (digitsSum[sum] != -1) {
      maxSum = std::max(maxSum, digitsSum[sum] + nums[i]);
      digitsSum[sum] = std::max(digitsSum[sum], nums[i]);
    } else {
      digitsSum[sum] = nums[i];
    }
  }

  return maxSum;
}

int main()
{
  // 2342. Max Sum of a Pair With Equal Sum of Digits

  {
    std::vector<int> nums = {18, 43, 36, 13, 7};
    assert(maximumSum(nums) == 54);
    assert(maximumSum_v2(nums) == 54);
  }

  {
    std::vector<int> nums = {10, 12, 19, 14};
    assert(maximumSum(nums) == -1);
    assert(maximumSum_v2(nums) == -1);
  }

  return 0;
}
