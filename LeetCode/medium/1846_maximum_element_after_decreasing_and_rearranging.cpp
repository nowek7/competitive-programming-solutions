#include <algorithm>
#include <cassert>
#include <vector>

int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr)
{
  std::sort(arr.begin(), arr.end());
  int smallestNum = 1;
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i] > smallestNum) {
      smallestNum = smallestNum + 1;
    }
  }
  return smallestNum;
}

int main()
{
  // 1846. Maximum Element After Decreasing and Rearranging
  {
    std::vector<int> nums = {2, 2, 1, 2, 1};
    assert(maximumElementAfterDecrementingAndRearranging(nums) == 2);
  }

  {
    std::vector<int> nums = {73, 98, 9};
    assert(maximumElementAfterDecrementingAndRearranging(nums) == 3);
  }

  return 0;
}
