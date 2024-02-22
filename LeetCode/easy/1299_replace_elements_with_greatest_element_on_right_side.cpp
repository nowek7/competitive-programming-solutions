#include <cassert>
#include <vector>

std::vector<int> replaceElements(std::vector<int>& arr)
{
  int maxElem = arr.back();
  arr[arr.size() - 1] = -1;
  for (int i = arr.size() - 2; i >= 0; --i) {
    int tmp = arr[i];
    arr[i] = maxElem;
    maxElem = std::max(maxElem, tmp);
  }

  return arr;
}

int main()
{
  // 1299. Replace Elements with Greatest Element on Right Side

  {
    std::vector<int> arr = {1, 2};
    std::vector<int> expected = {2, -1};
    assert(replaceElements(arr) == expected);
  }

  {
    std::vector<int> arr = {17, 18, 5, 4, 6, 1};
    std::vector<int> expected = {18, 6, 6, 6, 1, -1};
    assert(replaceElements(arr) == expected);
  }

  {
    std::vector<int> arr = {1, 2, 3};
    std::vector<int> expected = {3, 3, -1};
    assert(replaceElements(arr) == expected);
  }

  {
    std::vector<int> arr = {1000};
    std::vector<int> expected = {-1};
    assert(replaceElements(arr) == expected);
  }

  return 0;
}
