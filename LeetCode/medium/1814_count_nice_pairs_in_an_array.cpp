#include <cassert>
#include <unordered_map>
#include <vector>

int countNicePairs(std::vector<int>& nums)
{
  const int mod = 1e9 + 7;
  auto rev = [](int num) {
    int reversed = 0;
    for (; num > 0; num = num / 10) {
      reversed = (reversed * 10) + (num % 10);
    }
    return reversed;
  };

  int result = 0;
  std::unordered_map<int, int> frequencies;
  for (int i = 0; i < nums.size(); ++i) {
    const int reversed = rev(nums[i]);
    if (frequencies.find(nums[i] - reversed) != frequencies.end()) {
      result = (result + frequencies[nums[i] - reversed]) % mod;
    }
    ++frequencies[nums[i] - reversed];
  }

  return result;
}

int main()
{
  // 1814. Count Nice Pairs in an Array

  {
    std::vector<int> nums = {42, 11, 1, 97};
    assert(countNicePairs(nums) == 2);
  }

  {
    std::vector<int> nums = {13, 10, 35, 24, 76};
    assert(countNicePairs(nums) == 4);
  }

  return 0;
}
