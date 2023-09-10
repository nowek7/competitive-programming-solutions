#include <algorithm>
#include <vector>

#include <iostream>

int removeElement(std::vector<int>& nums, int value)
{
    auto it = std::remove(nums.begin(), nums.end(), value);
    return std::distance(nums.begin(), it);
}

int removeElement_v2(std::vector<int>& nums, int value)
{
    int count = 0;

    int start = 0;
    int end = nums.size() - 1;
    while (start < end) {
        if (nums[start] == value) {
            std::swap(nums[start], nums[end]);
            --end;
        } else {
            ++start;
        }
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == value) {
            ++count;
        }
    }

    return nums.size() - count;
}

void print(const std::vector<int>& nums)
{
    for (auto i = 0; i < nums.size() - 1; ++i) {
        std::cout << nums.at(i) << " ";
    }
    std::cout << *nums.rbegin() << '\n';
}

int main()
{
    // 27. Remove Element
    {
        std::vector<int> nums = {3, 2, 2, 3};
        int k = removeElement(nums, 3);
        std::cout << k << '\n';
    }

    {
        std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
        int k = removeElement_v2(nums, 2);
        std::cout << k << '\n';
    }

    return 0;
}