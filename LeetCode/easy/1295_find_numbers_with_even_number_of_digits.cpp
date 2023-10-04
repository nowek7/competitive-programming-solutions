#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

void print(int number)
{
  std::cout << "Length of number " << number << " -> " << static_cast<int>(std::floor(std::log10(number))) + 1 << '\n';
}

int findNumbers(std::vector<int>& nums)
{
  int count = 0;
  for (int i = 0; i < nums.size(); ++i) {
    count += (static_cast<int>(std::floor(std::log10(nums.at(i)))) + 1) % 2 == 0;
  }
  return count;
}

int main()
{
  // 1295. Find Numbers with Even Number of Digits
  {
    std::vector<int> nums = {12, 345, 2, 6, 7896};
    const int result = findNumbers(nums);
    assert(result == 2);
  }

  {
    std::vector<int> nums = {555, 901, 482, 1771};
    const int result = findNumbers(nums);
    assert(result == 1);
  }

  return 0;
}