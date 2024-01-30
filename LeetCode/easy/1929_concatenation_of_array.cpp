#include <iostream>
#include <vector>

std::vector<int> getConcatenation(std::vector<int>& nums)
{
  std::vector<int> result;
  result.reserve(nums.size() * 2);

  for (int i = 0; i < 2; ++i) {
    result.insert(result.end(), nums.begin(), nums.end());
  }

  return result;
}

void printSums(const std::vector<int>& sums)
{
  for (auto i = 0; i < sums.size() - 1; ++i) {
    std::cout << sums.at(i) << " ";
  }
  std::cout << *sums.rbegin() << '\n';
}

int main()
{
  // 1929. Concatenation of Array
  {
    std::vector<int> nums = {1, 2, 3, 4};
    auto concatenation = getConcatenation(nums);
    printSums(concatenation);
  }

  {
    std::vector<int> nums = {1, 1, 1, 1, 1};
    auto concatenation = getConcatenation(nums);
    printSums(concatenation);
  }

  {
    std::vector<int> nums = {3, 1, 2, 10, 1};
    auto concatenation = getConcatenation(nums);
    printSums(concatenation);
  }

  return 0;
}
