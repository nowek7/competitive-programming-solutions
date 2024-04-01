#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

bool divideArray(std::vector<int>& nums)
{
  std::unordered_map<int, int> elements;
  for (auto value: nums) {
    ++elements[value];
  }

  return !std::any_of(elements.begin(), elements.end(), [](auto element) {
    return element.second % 2 == 1;
  });
}

int main()
{
  // 2206. Divide Array Into Equal Pairs

  {
    std::vector<int> nums = {3, 2, 3, 2, 2, 2};
    assert(divideArray(nums) == true);
  }

  {
    std::vector<int> nums = {1, 2, 3, 4};
    assert(divideArray(nums) == false);
  }

  return 0;
}
