#include <cassert>
#include <queue>
#include <vector>

int thirdMax(std::vector<int>& nums)
{
  std::priority_queue<int> pq(nums.begin(), nums.end());

  int maxElement = pq.top();
  int thirdMaxElement = pq.top();
  pq.pop();

  int counter = 2;
  while (counter > 0 && !pq.empty()) {
    if (thirdMaxElement != pq.top()) {
      thirdMaxElement = pq.top();
      --counter;
    }
    pq.pop();
  }

  if (counter == 0) {
    return thirdMaxElement;
  } else {
    return maxElement;
  }
}

int main()
{
  // 414. Third Maximum Number

  {
    std::vector<int> nums = {3, 2, 1};
    assert(thirdMax(nums) == 1);
  }

  {
    std::vector<int> nums = {2, 1};
    assert(thirdMax(nums) == 2);
  }

  {
    std::vector<int> nums = {1, 2, -2147483648};
    assert(thirdMax(nums) == -2147483648);
  }

  {
    std::vector<int> nums = {1, 1, 1};
    assert(thirdMax(nums) == 1);
  }

  return 0;
}