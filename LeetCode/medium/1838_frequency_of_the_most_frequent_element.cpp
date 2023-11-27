#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int maxFrequency(std::vector<int>& nums, int k)
{
  std::sort(nums.begin(), nums.end());

  int maxFrequency = 1;
  for (int i = nums.size() - 1; i > 0 && maxFrequency <= i; --i) {
    int numOps = k;
    int freq = 1;
    for (int j = i - 1; j >= 0 && numOps >= 0; --j) {
      const int diff = nums[i] - nums[j];
      if (diff > numOps) {
        break;
      }

      numOps -= diff;
      if (numOps >= 0) {
        ++freq;
      }
    }
    maxFrequency = std::max(maxFrequency, freq);
  }

  return maxFrequency;
}

int maxFrequency_v2(std::vector<int>& nums, int k)
{
  std::sort(nums.begin(), nums.end());

  int maxFrequency = 0;
  int left = 0;
  long curr = 0;
  for (int right = 0; right < nums.size(); ++right) {
    long target = nums[right];
    curr += nums[right];
    while ((right - left + 1) * target - curr > k) {
      curr -= nums[left];
      ++left;
    }
    maxFrequency = std::max(maxFrequency, right - left + 1);
  }

  return maxFrequency;
}

int maxFrequency_v3(std::vector<int>& nums, int k)
{
  return 0;
}

void printArr(const std::vector<int>& nums)
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
  // 1838. Frequency of the Most Frequent Element

  {
    std::vector<int> nums = {1, 2, 4};
    std::cout << maxFrequency_v2(nums, 5) << '\n';
  }

  {
    std::vector<int> nums = {1, 4, 8, 13};
    std::cout << maxFrequency_v2(nums, 5) << '\n';
  }

  {
    std::vector<int> nums = {3, 9, 6};
    std::cout << maxFrequency(nums, 2) << '\n';
  }

  {
    std::vector<int> nums = {3, 3, 3, 3, 4};
    std::cout << maxFrequency(nums, 4) << '\n';
  }

  {
    std::vector<int> nums = {9930, 9923, 9983,  9997, 9934, 9952, 9945, 9914, 9985, 9982, 9970, 9932, 9985, 9902, 9975,
                             9990, 9922, 9990,  9994, 9937, 9996, 9964, 9943, 9963, 9911, 9925, 9935, 9945, 9933, 9916,
                             9930, 9938, 10000, 9916, 9911, 9959, 9957, 9907, 9913, 9916, 9993, 9930, 9975, 9924, 9988,
                             9923, 9910, 9925,  9977, 9981, 9927, 9930, 9927, 9925, 9923, 9904, 9928, 9928, 9986, 9903,
                             9985, 9954, 9938,  9911, 9952, 9974, 9926, 9920, 9972, 9983, 9973, 9917, 9995, 9973, 9977,
                             9947, 9936, 9975,  9954, 9932, 9964, 9972, 9935, 9946, 9966};
    std::cout << maxFrequency_v2(nums, 3056) << '\n';
  }

  return 0;
}