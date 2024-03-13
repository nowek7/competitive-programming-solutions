#include <cassert>
#include <cmath>
#include <vector>

int differenceOfSum(std::vector<int>& nums)
{
  auto sumOfDigits = [](int number) {
    int sum = 0;
    while (number > 0) {
      sum += number % 10;
      number /= 10;
    }
    return sum;
  };

  int elementSum = 0;
  int digitSum = 0;
  for (auto item: nums) {
    elementSum += item;
    digitSum += sumOfDigits(item);
  }

  return std::abs(elementSum - digitSum);
}

int main()
{
  // 2535. Difference Between Element Sum and Digit Sum of an Array

  {
    std::vector<int> nums = {1, 15, 6, 3};
    assert(differenceOfSum(nums) == 9);
  }

  {
    std::vector<int> nums = {1, 2, 3, 4};
    assert(differenceOfSum(nums) == 0);
  }

  return 0;
}