#include <iostream>
#include <vector>

void rotate(std::vector<int>& arr, int k)
{
  const int n = arr.size();
  k %= n;

  std::vector<int> rotated(n);
  for (int i = 0; i < n; ++i) {
    rotated[(i + k) % n] = arr[i];
  }
  arr = rotated;
}

void printNums(const std::vector<int>& nums)
{
  if (!nums.empty()) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      std::cout << nums[i] << " ";
    }
    std::cout << nums.back() << '\n';
  }
}

int main()
{
  // 189. Rotate Array
  {
    std::vector<int> nums = {-1, -100, 3, 99};
    rotate(nums, 2);
    printNums(nums);
  }
}
