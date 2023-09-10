#include <vector>
#include <unordered_map>

#include <iostream>

int singleNumber(std::vector<int>& numbers) 
{
    std::unordered_map<int, int> dict;
    for (auto num: numbers) {
        ++dict[num];
    }

    for (auto num: numbers) {
        if (dict.at(num) == 1) {
            return num;
        }
    }

    return 0;        
}

int singleNumber_v2(std::vector<int>& numbers) 
{
    int result = 0;
    for (auto num: numbers) {
        result ^= num;
        std::cout << result << '\n';
    }
    return result;
}

int main()
{
    // {
    //     std::vector<int> numbers = {2, 2, 1};
    //     std::cout << singleNumber_v2(numbers) << '\n';
    // }

    {
        std::vector<int> numbers = {4, 1, 2, 1, 2};
        std::cout << singleNumber_v2(numbers) << '\n';
    }

    // {
    //     std::vector<int> numbers = {2, 2, 1};
    //     std::cout << singleNumber(numbers) << '\n';
    // }

    // {
    //     std::vector<int> numbers = {2};
    //     std::cout << singleNumber(numbers) << '\n';
    // }

    return 0;
}