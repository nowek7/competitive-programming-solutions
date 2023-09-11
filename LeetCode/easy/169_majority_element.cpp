#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

int majorityElement(std::vector<int>& nums) 
{
    // Complexity O(n)
    int count = 0;
    int majority = nums.at(0);
    for (auto number: nums) {
        if (number == majority) {
            count++;
        } else {
            count--;
        }

        if (count < 0) {
            majority = number;
            count = 0;
        }
    }

    return majority;
}

int majorityElement_v2(std::vector<int>& nums) 
{
    // Complexity O(n * long(n))
    std::unordered_map<int, int> elements;
    for (auto number: nums) {
        ++elements[number];
    }

    for (auto [number, count]: elements) {
        if (count > nums.size() * 0.5) {
            return number;
        }
    }
    return 0;
}

int majorityElement_v3(std::vector<int>& nums) 
{
    // Complexity O(n * long(n))
    std::sort(nums.begin(), nums.end());
    return nums.at(nums.size() * 0.5);
}

int main()
{
    // 169. Majority Element
    {
        std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        std::cout << majorityElement_v3(nums) << '\n';
    }

    {
        std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        std::cout << majorityElement(nums) << '\n';
    }

    return 0;
}