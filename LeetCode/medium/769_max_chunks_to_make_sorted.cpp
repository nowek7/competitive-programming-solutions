#include <cassert>
#include <vector>

int maxChunksToSorted(std::vector<int>& arr)
{
  int result = 0;

  int prefixSums = 0;
  int sum = 0;
  for (auto i = 0; i < arr.size(); ++i) {
    prefixSums += arr[i];
    sum += i;

    if (prefixSums == sum) {
      ++result;
    }
  }

  return result;
}

int main()
{
  // 769. Max Chunks To Make Sorted

  {
    std::vector<int> arr = {4, 3, 2, 1, 0};
    assert(maxChunksToSorted(arr) == 1);
  }

  {
    std::vector<int> arr = {1, 0, 2, 3, 4};
    assert(maxChunksToSorted(arr) == 4);
  }

  {
    std::vector<int> arr = {0, 3, 1, 4, 2, 5, 6};
    assert(maxChunksToSorted(arr) == 4);
  }

  return 0;
}
