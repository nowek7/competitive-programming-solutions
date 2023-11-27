#include <cassert>
#include <map>
#include <vector>

int reductionOperations(std::vector<int>& nums)
{
  std::map<int, int> frequencies;
  for (auto num: nums) {
    ++frequencies[num];
  }

  int numOps = 0;
  int i = 0;
  for (auto [num, freq]: frequencies) {
    numOps += i * freq;
    ++i;
  }

  return numOps;
}

int main()
{
  // 1887. Reduction Operations to Make the Array Elements Equal

  {
    std::vector<int> nums = {5, 1, 3};
    assert(reductionOperations(nums) == 3);
  }

  {
    std::vector<int> nums = {1, 1, 1};
    assert(reductionOperations(nums) == 0);
  }

  return 0;
}
