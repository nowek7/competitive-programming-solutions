#include <array>
#include <cassert>
#include <numeric>
#include <vector>

int maxFrequencyElements(std::vector<int>& nums)
{
  std::array<int, 100> frequencies {0};
  int numberWithMaxFrequency = nums[0];
  for (auto num: nums) {
    ++frequencies[num - 1];
    if (frequencies[numberWithMaxFrequency - 1] < frequencies[num - 1]) {
      numberWithMaxFrequency = num;
    }
  }

  int sum = std::accumulate(frequencies.begin(), frequencies.end(), 0, [&](int acc, int freq) {
    return acc + (freq == frequencies[numberWithMaxFrequency - 1] ? freq : 0);
  });

  return sum;
}

int main()
{
  // 3005. Count Elements With Maximum Frequency

  {
    std::vector<int> nums = {1, 2, 2, 3, 1, 4};
    assert(maxFrequencyElements(nums) == 4);
  }

  {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    assert(maxFrequencyElements(nums) == 5);
  }

  return 0;
}