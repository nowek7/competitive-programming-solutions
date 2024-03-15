#include <cassert>
#include <vector>

int atMost(std::vector<int>& nums, int goal)
{
  if (goal < 0) {
    return 0;
  }

  int tail = 0;
  int sum = 0;
  int result = 0;
  for (int head = 0; head < nums.size(); ++head) {
    sum += nums[head];
    while (sum > goal && tail <= head) {
      sum -= nums[tail];
      ++tail;
    }
    result += head - tail + 1;
  }
  return result;
}

int numSubarraysWithSum(std::vector<int>& nums, int goal)
{
  return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main()
{
  // 930. Binary Subarrays With Sum

  {
    std::vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    assert(numSubarraysWithSum(nums, goal) == 4);
  }

  {
    std::vector<int> nums = {0, 0, 0, 0, 0};
    int goal = 0;
    assert(numSubarraysWithSum(nums, goal) == 15);
  }

  return 0;
}