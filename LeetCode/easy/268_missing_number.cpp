#include <numeric>
#include <vector>

#include <iostream>

int missingNumber(std::vector<int>& nums)
{
    const int expected = nums.size() * 0.5 * (nums.size() + 1);
    const int sum = std::accumulate(nums.begin(), nums.end(), 0);
    return expected - sum;
}

int main()
{
    // 268. Missing Number
    {
        std::vector<int> nums = {3, 0, 1};
        std::cout << missingNumber(nums) << '\n';
    }

    {
        std::vector<int> nums = {0, 1};
        std::cout << missingNumber(nums) << '\n';
    }

    {
        std::vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
        std::cout << missingNumber(nums) << '\n';
    }

    return 0;
}