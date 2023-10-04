#include <iostream>
#include <vector>

int findIdxOfTarget(const std::vector<int>& nums, int target)
{
  int idx = -1;

  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int idx = (left + right) * 0.5;
    if (nums[idx] < target) {
      left = idx + 1;
    } else if (nums[idx] > target) {
      right = idx - 1;
    } else {
      return idx;
    }
  }

  return idx;
}

std::vector<int> searchRange(std::vector<int>& nums, int target)
{
  if (nums.empty()) {
    return {-1, -1};
  }

  if (target < nums[0] || target > nums[nums.size() - 1]) {
    return {-1, -1};
  }

  const int idx = findIdxOfTarget(nums, target);
  if (idx == -1) {
    return {-1, -1};
  }

  int lowerIdx = idx;
  while (lowerIdx > 0 && nums[lowerIdx - 1] == target) {
    --lowerIdx;
  }

  int upperIdx = idx;
  while ((upperIdx + 1 < nums.size()) && nums[upperIdx + 1] == target) {
    ++upperIdx;
  }

  return {lowerIdx, upperIdx};
}

std::vector<int> searchRange_2(std::vector<int>& nums, int target)
{
  std::vector<int> indices;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] == target) {
      indices.push_back(i);
    }
  }

  if (indices.empty()) {
    return {-1, -1};
  } else {
    return {indices[0], indices[indices.size() - 1]};
  }
}

std::vector<int> searchRange_v3(std::vector<int>& nums, int target)
{
  int start = -1;
  int end = -1;

  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] == target) {
      if (start == -1) {
        start = i;
      }
      end = i;
    }
  }

  return {start, end};
}

int main()
{
  // 34. Find First and Last Position of Element in Sorted Array
  {
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    std::vector<int> range = searchRange(nums, 8);
    std::cout << range[0] << " " << range[1] << '\n';
  }

  {
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    std::vector<int> range = searchRange_2(nums, 7);
    std::cout << range[0] << " " << range[1] << '\n';
  }

  {
    std::vector<int> nums = {};
    std::vector<int> range = searchRange(nums, 0);
    std::cout << range[0] << " " << range[1] << '\n';
  }

  {
    std::vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> range = searchRange(nums, 1);
    std::cout << range[0] << " " << range[1] << '\n';
  }

  {
    std::vector<int> nums = {1};
    std::vector<int> range = searchRange(nums, 1);
    std::cout << range[0] << " " << range[1] << '\n';
  }

  return 0;
}