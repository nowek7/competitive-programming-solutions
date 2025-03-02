#include <cassert>
#include <unordered_map>
#include <vector>

int tupleSameProduct(std::vector<int>& nums)
{
  std::unordered_map<int, int> productFrequency;
  for (auto i = 0; i < nums.size() - 1; ++i) {
    for (auto j = i + 1; j < nums.size(); ++j) {
      const int product = nums[i] * nums[j];
      ++productFrequency[product];
    }
  }

  int result = 0;
  for (auto& [product, counter]: productFrequency) {
    const int numPairs = (counter - 1) * counter / 2;
    result += 8 * numPairs;
  }

  return result;
}

int main()
{
  // 1726. Tuple with Same Product

  {
    std::vector<int> nums = {2, 3, 4, 6};
    assert(tupleSameProduct(nums) == 8);
  }

  {
    std::vector<int> nums = {1, 2, 4, 5, 10};
    assert(tupleSameProduct(nums) == 16);
  }

  return 0;
}
