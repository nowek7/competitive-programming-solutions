#include <cassert>
#include <string>
#include <vector>

std::string triangleType(std::vector<int>& nums)
{
  const int sideA = nums[0];
  const int sideB = nums[1];
  const int sideC = nums[2];

  if (sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA) {
    if (sideA == sideB && sideB == sideC) {
      return "equilateral";
    } else if (sideA == sideB || sideB == sideC || sideA == sideC) {
      return "isosceles";
    } else {
      return "scalene";
    }
  }

  return "none";
}

int main()
{
  // 3024. Type of Triangle

  {
    std::vector<int> nums = {3, 3, 3};
    assert(triangleType(nums) == "equilateral");
  }

  {
    std::vector<int> nums = {3, 4, 5};
    assert(triangleType(nums) == "scalene");
  }

  {
    std::vector<int> nums = {1, 2, 3};
    assert(triangleType(nums) == "none");
  }

  return 0;
}
