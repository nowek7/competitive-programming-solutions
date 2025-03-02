#include <cassert>
#include <unordered_set>
#include <vector>

int lenLongestFibSubseq(std::vector<int>& arr)
{
  std::unordered_set<int> numbers(arr.begin(), arr.end());

  int maxResult = 0;
  for (int i = 0; i < arr.size(); ++i) {
    for (int j = i + 1; j < arr.size(); ++j) {
      int prev = arr[j];
      int curr = arr[i] + arr[j];
      int result = 2;

      while (numbers.count(curr)) {
        int temp = curr;
        curr += prev;
        prev = temp;
        maxResult = std::max(maxResult, ++result);
      }
    }
  }

  return maxResult;
}

int main()
{
  // 873. Length of Longest Fibonacci Subsequence

  {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    assert(lenLongestFibSubseq(arr) == 5);
  }

  {
    std::vector<int> arr = {1, 3, 7, 11, 12, 14, 18};
    assert(lenLongestFibSubseq(arr) == 3);
  }

  return 0;
}
