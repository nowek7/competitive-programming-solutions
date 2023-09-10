#include <vector>
#include <unordered_map>

#include <iostream>

std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
    std::vector<int> result(2);

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return result;
}

std::vector<int> twoSum_v2(std::vector<int>& nums, int target) 
{
    std::unordered_map<int, int> traversed;

    for (int i = 0; i < nums.size(); ++i) {
        const int x = target - nums[i];
        if (traversed.find(x) != traversed.end()) {
            return {i, traversed[x]};
        }

        traversed[nums[i]] = i;
    }

    return {-1, -1};
}

int main()
{
    // 1. Two Sum
    {
        std::vector<int> nums = {2, 7, 11, 15};
        const int target = 9;

        auto results = twoSum(nums, target);
        std::cout << results[0] << " " << results[1] << '\n';
    }

    {
        std::vector<int> nums = {3, 2, 4};
        const int target = 6;

        auto results = twoSum_v2(nums, target);
        std::cout << results[0] << " " << results[1] << '\n';
    }

    {
        std::vector<int> nums = {3, 3};
        const int target = 6;

        auto results = twoSum(nums, target);
        std::cout << results[0] << " " << results[1] << '\n';
    }

    return 0;
}