#include <vector>

#include <iostream>

std::vector<int> runningSum(std::vector<int>& nums)
{
    std::vector<int> sums(nums.size());

    sums[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        sums[i] += sums[i - 1] + nums[i];
    }

    return sums;
}

void printSums(const std::vector<int>& sums)
{
    for (auto i = 0; i < sums.size() - 1; ++i) {
        std::cout << sums.at(i) << " ";
    }
    std::cout << *sums.rbegin() << '\n';
}

int main()
{
    // 1480. Running Sum of 1d Array
    {
        std::vector<int> nums = {1, 2, 3, 4};
        auto sums = runningSum(nums);
        printSums(sums);
    }

    {
        std::vector<int> nums = {1, 1, 1, 1, 1};
        auto sums = runningSum(nums);
        printSums(sums);
    }

    {
        std::vector<int> nums = {3, 1, 2, 10, 1};
        auto sums = runningSum(nums);
        printSums(sums);
    }

    return 0;
}