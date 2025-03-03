#include <cassert>
#include <vector>

std::vector<int> pivotArray(std::vector<int>& nums, int pivot)
{
  std::vector<int> beforePivot;
  std::vector<int> pivots;
  std::vector<int> afterPivots;

  for (auto i = 0; i < nums.size(); ++i) {
    if (nums[i] < pivot) {
      beforePivot.push_back(nums[i]);
    } else if (nums[i] == pivot) {
      pivots.push_back(nums[i]);
    } else {
      afterPivots.push_back(nums[i]);
    }
  }

  std::vector<int> result;
  result.reserve(nums.size());
  for (auto num: beforePivot) {
    result.push_back(num);
  }
  for (auto num: pivots) {
    result.push_back(num);
  }
  for (auto num: afterPivots) {
    result.push_back(num);
  }

  return result;
}

std::vector<int> pivotArray_v2(std::vector<int>& nums, int pivot)
{
  std::vector<int> result(nums.size());

  int numPivots = 0;
  int idx = 0;
  for (auto i = 0; i < nums.size(); ++i) {
    if (nums[i] < pivot) {
      result[idx] = nums[i];
      ++idx;
    } else if (nums[i] == pivot) {
      ++numPivots;
    }
  }

  while (numPivots > 0) {
    result[idx] = pivot;
    ++idx;
    --numPivots;
  }

  for (auto i = 0; i < nums.size(); ++i) {
    if (nums[i] > pivot) {
      result[idx] = nums[i];
      ++idx;
    }
  }

  return result;
}

int main()
{
  // 2161. Partition Array According to Given Pivot

  {
    std::vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;
    std::vector<int> expected = {9, 5, 3, 10, 10, 12, 14};
    {
      std::vector<int> result = pivotArray(nums, pivot);
      assert(result == expected);
    }
    {
      std::vector<int> result = pivotArray_v2(nums, pivot);
      assert(result == expected);
    }
  }

  {
    std::vector<int> nums = {-3, 4, 3, 2};
    int pivot = 2;
    std::vector<int> expected = {-3, 2, 4, 3};

    {
      std::vector<int> result = pivotArray(nums, pivot);
      assert(result == expected);
    }
    {
      std::vector<int> result = pivotArray_v2(nums, pivot);
      assert(result == expected);
    }
  }

  return 0;
}
