#include <cassert>
#include <vector>

int sumOfUnique(std::vector<int>& nums)
{
  std::vector<int> frequency(101, 0);
  for (auto number: nums) {
    ++frequency[number];
  }

  int sum = 0;
  for (std::size_t number = 0; number < frequency.size(); ++number) {
    if (frequency[number] == 1) {
      sum += number;
    }
  }

  return sum;
}

int main()
{
  // 1748. Sum of Unique Elements

  {
    std::vector<int> nums = {1, 2, 3, 2};
    assert(sumOfUnique(nums) == 4);
  }

  {
    std::vector<int> nums = {1, 1, 1, 1, 1};
    assert(sumOfUnique(nums) == 0);
  }

  {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    assert(sumOfUnique(nums) == 15);
  }

  return 0;
}
