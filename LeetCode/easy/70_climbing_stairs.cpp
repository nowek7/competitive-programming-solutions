#include <vector>
#include <string>
#include <iostream>

int climbStairs(int n)
{
    std::vector<int> results = {1, 2};
    for (int i = 3; i <= n; ++i) {
        int tmp = results[0];
        results[0] = results[1];
        results[1] = tmp + results[0];
    }
    return (n == 1) ? results.at(0) : results.at(1);
}

int main()
{
    // 70. Climbing Stairs
    for (int i = 1; i < 10; ++i) {
        std::cout << i << " -> " << climbStairs(i) << '\n';
    }

    return 0;
}