#include <vector>

#include <iostream>

int searchInsert(std::vector<int>& nums, int target)
{
    if (target < nums.front()) {
        return 0;
    }
    if (target > nums.back()) {
        return nums.size();
    }

    int idx = 0;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        idx = (left + right) * 0.5;
        if (nums.at(idx) < target) {
            left = idx + 1;
        } else if (nums.at(idx) > target) {
            right = idx - 1;
        } else {
            return idx;
        }
    }

    return left;
}

int main()
{
    // 35. Search Insert Position
    {
        std::vector<int> nums = {1, 3, 5, 6};
        int target = 5;
        std::cout << searchInsert(nums, target) << '\n';
    }

    {
        std::vector<int> nums = {1, 3, 5, 6};
        int target = 2;
        std::cout << searchInsert(nums, target) << '\n';
    }

    {
        std::vector<int> nums = {1, 3, 5, 6};
        int target = 7;
        std::cout << searchInsert(nums, target) << '\n';
    }

    {
        std::vector<int> nums = {1, 3, 5, 6};
        int target = 0;
        std::cout << searchInsert(nums, target) << '\n';
    }

    {
        std::vector<int> nums = {1, 3};
        int target = 1;
        std::cout << searchInsert(nums, target) << '\n';
    }

    {
        std::vector<int> nums = {1, 3, 5};
        int target = 4;
        std::cout << searchInsert(nums, target) << '\n';
    }

    {
        std::vector<int> nums = {1, 3};
        int target = 3;
        std::cout << searchInsert(nums, target) << '\n';
    }

    return 0;
}