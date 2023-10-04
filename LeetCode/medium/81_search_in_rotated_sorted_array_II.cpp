#include <cassert>
#include <iostream>
#include <vector>

bool search(std::vector<int>& nums, int target)
{
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums.at(mid) == target) {
      return true;
    }

    // Eliminate duplicates
    if (nums.at(left) == nums.at(mid) && nums.at(right) == nums.at(mid)) {
      ++left;
      --right;
    } else if (nums.at(left) <= nums.at(mid)) {
      // First half
      if (nums.at(left) <= target && nums.at(mid) > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      // Second half
      if (nums.at(right) >= target && nums.at(mid) < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }

  return false;
}

int main()
{
  // 81. Search in Rotated Sorted Array II
  {
    std::vector<int> nums = {9, 9, 0, 1, 2, 2, 3, 4};
    std::cout << (search(nums, 0) ? "Contain" : "Not contain") << '\n';
  }

  {
    std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    std::cout << (search(nums, 3) ? "Contain" : "Not contain") << '\n';
  }

  {
    std::vector<int> nums = {1};
    assert(search(nums, 0) == false);
    assert(search(nums, 1) == true);
    assert(search(nums, 2) == false);
    assert(search(nums, 3) == false);
  }

  {
    std::vector<int> nums = {1, 0, 1, 1, 1};
    std::cout << (search(nums, 0) ? "Contain" : "Not contain") << '\n';
    for (int i = 0; i < 2; ++i) {
      assert(search(nums, i));
    }
  }

  {
    std::vector<int> nums = {5, 6, 7, 0, 1, 2, 3, 4};
    for (auto i = 0; i < 8; ++i) {
      assert(search(nums, i));
    }
  }

  return 0;
}