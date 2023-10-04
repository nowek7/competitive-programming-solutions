#include <iostream>
#include <vector>

std::vector<int> sortedSquares(std::vector<int>& nums)
{
  std::vector<int> squares(nums.size(), 0);
  for (int i = 0, j = nums.size() - 1, pos = nums.size() - 1; i <= j; --pos) {
    const int left = nums.at(i) * nums.at(i);
    const int right = nums.at(j) * nums.at(j);
    if (left > right) {
      squares[pos] = left;
      ++i;
    } else {
      squares[pos] = right;
      --j;
    }
  }
  return squares;
}

void print(std::vector<int>& sequence)
{
  if (!sequence.empty()) {
    for (int i = 0; i < sequence.size() - 1; ++i) {
      std::cout << sequence.at(i) << " ";
    }
    std::cout << *sequence.rbegin() << '\n';
  }
}

int main()
{
  // 977. Squares of a Sorted Array
  {
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    std::vector<int> result = sortedSquares(nums);
    print(result);
  }

  {
    std::vector<int> nums = {};
    std::vector<int> result = sortedSquares(nums);
    print(result);
  }

  return 0;
}