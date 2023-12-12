#include <cassert>
#include <vector>

int findSpecialInteger(std::vector<int>& arr)
{
  if (arr.size() == 1) {
    return arr.front();
  }

  const int threshold = arr.size() * 0.25;
  int freq = 1;
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i - 1] == arr[i]) {
      ++freq;
      if (freq > threshold) {
        return arr[i - 1];
      }
    } else {
      freq = 1;
    }
  }
  return -1;
}

int main()
{
  // 1287. Element Appearing More Than 25% In Sorted Array

  {
    std::vector<int> nums = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    assert(findSpecialInteger(nums) == 6);
  }

  {
    std::vector<int> nums = {1, 1};
    assert(findSpecialInteger(nums) == 1);
  }

  return 0;
}
