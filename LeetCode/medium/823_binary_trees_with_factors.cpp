#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>
#include <unordered_map>
#include <vector>

int numFactoredBinaryTrees(std::vector<int>& arr)
{
  std::sort(arr.begin(), arr.end());
  std::set<int> uniqueArr(arr.begin(), arr.end());

  std::unordered_map<int, int> dp;
  for (int num: arr) {
    dp[num] = 1;
  }

  const int mod = 1e9 + 7;

  for (int i: arr) {
    for (int j: arr) {
      if (j > std::sqrt(i)) {
        break;
      }

      if (i % j == 0 && uniqueArr.find(i / j) != uniqueArr.end()) {
        long long temp = static_cast<long long>(dp[j]) * dp[i / j];
        if (i / j == j) {
          dp[i] = (dp[i] + temp) % mod;
        } else {
          dp[i] = (dp[i] + temp * 2) % mod;
        }
      }
    }
  }

  int result = 0;
  for (auto& [_, val]: dp) {
    result = (result + val) % mod;
  }
  return result;
}

int main()
{
  // 823. Binary Trees With Factors

  {
    std::vector<int> arr = {2, 4};
    assert(numFactoredBinaryTrees(arr) == 3);
  }

  {
    std::vector<int> arr = {2, 4, 5, 10};
    assert(numFactoredBinaryTrees(arr) == 7);
  }

  return 0;
}