#include <array>
#include <cassert>
#include <vector>

bool doesValidArrayExist(std::vector<int>& derived)
{
  std::array<int, 2> tmp {0};
  for (auto i = 0, j = 1; i < derived.size() - 1 && j < derived.size(); ++i, ++j) {
    tmp[1] ^= derived[i];
    tmp[0] ^= derived[j];
  }

  if (tmp[0] == derived.front() && tmp[1] == derived.back()) {
    return true;
  } else {
    return false;
  }
}

int main()
{
  // 2683. Neighboring Bitwise XOR

  {
    std::vector<int> nums = {1, 1, 0};
    assert(doesValidArrayExist(nums) == true);
  }

  {
    std::vector<int> nums = {1, 1};
    assert(doesValidArrayExist(nums) == true);
  }

  {
    std::vector<int> nums = {1, 0};
    assert(doesValidArrayExist(nums) == false);
  }

  return 0;
}
