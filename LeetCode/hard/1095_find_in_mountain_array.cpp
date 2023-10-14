#include <iostream>
#include <vector>

int getPeekIdxFromMountainArray(const std::vector<int>& mountainArr)
{
  int left = 0;
  int right = mountainArr.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) * 0.5;
    if (mountainArr.at(mid - 1) < mountainArr.at(mid) && mountainArr.at(mid) > mountainArr.at(mid + 1)) {
      return mid;
    }

    if (mountainArr.at(mid) < mountainArr.at(mid + 1)) {
      left = mid;
    } else {
      right = mid;
    }
  }

  return right;
}

int findInMountainArray(int target, std::vector<int>& mountainArr)
{
  const int len = mountainArr.size();
  if (len < 3) {
    return -1;
  }

  const int peekIdx = getPeekIdxFromMountainArray(mountainArr);
  std::cout << "PeekIdx -> " << peekIdx << '\n';
  if (mountainArr.at(peekIdx) == target) {
    return peekIdx;
  } else {
    int left = 0;
    int right = peekIdx;
    while (left <= right) {
      int mid = left + (right - left) * 0.5;
      if (mountainArr.at(mid) < target) {
        left = mid + 1;
      } else if (mountainArr.at(mid) > target) {
        right = mid - 1;
      } else {
        return mid;
      }
    }

    left = peekIdx;
    right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) * 0.5;
      if (mountainArr.at(mid) > target) {
        left = mid + 1;
      } else if (mountainArr.at(mid) < target) {
        right = mid - 1;
      } else {
        return mid;
      }
    }
  }

  return -1;
}

int main()
{
  // 1095. Find in Mountain Array
  {
    std::vector<int> mountain = {1, 2, 3, 4, 5, 3, 1};
    std::cout << findInMountainArray(3, mountain) << '\n';
  }

  {
    std::vector<int> mountain = {0, 1, 2, 4, 2, 1};
    std::cout << findInMountainArray(3, mountain) << '\n';
  }

  {
    std::vector<int> mountain = {6, 7, 2};
    std::cout << findInMountainArray(2, mountain) << '\n';
  }

  {
    std::vector<int> mountain = {7, 17, 24, 28, 30, 33, 26, 20, 12, 2};
    std::cout << findInMountainArray(2, mountain) << '\n';
  }

  {
    std::vector<int> mountain = {3, 5, 3, 2, 0};
    std::cout << findInMountainArray(2, mountain) << '\n';
  }

  return 0;
}