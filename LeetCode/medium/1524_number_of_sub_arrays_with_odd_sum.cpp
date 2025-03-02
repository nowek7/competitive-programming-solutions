#include <cassert>
#include <vector>

int numOfSubarrays(std::vector<int>& arr)
{
  const int mod = 1e9 + 7;

  int result = 0;
  int prefSum = 0;
  int oddCount = 0;
  int evenCount = 1;
  for (auto num: arr) {
    prefSum += num;
    if (prefSum % 2 == 0) {
      result += oddCount;
      ++evenCount;
    } else {
      result += evenCount;
      ++oddCount;
    }

    result %= mod;
  }

  return result;
}

int main()
{
  // 1524. Number of Sub-arrays With Odd Sum

  {
    std::vector<int> arr = {1, 3, 5};
    assert(numOfSubarrays(arr) == 4);
  }

  {
    std::vector<int> arr = {2, 4, 6};
    assert(numOfSubarrays(arr) == 0);
  }

  {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    assert(numOfSubarrays(arr) == 16);
  }

  return 0;
}
