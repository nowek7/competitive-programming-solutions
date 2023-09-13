#include <numeric>
#include <vector>
#include <iostream>

int candy(std::vector<int>& ratings)
{
    std::vector<int> candies(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i) {
        if (ratings.at(i) > ratings.at(i - 1)) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = ratings.size() - 2; i > 0; --i) {
        if (ratings.at(i) > ratings.at(i + 1)) {
            if (candies.at(i + 1) >= candies.at(i)) {
                candies[i] = candies[i + 1] + 1;
            }
        }
    }

    return std::accumulate(candies.begin(), candies.end(), 0);
}

int main()
{
    // 135. Candy
    {
        std::vector<int> ratings = {1, 2, 2};
        std::cout << candy(ratings) << '\n';
    }

    {
        std::vector<int> ratings = {1, 0, 2};
        std::cout << candy(ratings) << '\n';
    }

    {
        std::vector<int> ratings = {1, 1, 2, 2};
        std::cout << candy(ratings) << '\n';
    }

    {
        std::vector<int> ratings = {2, 2, 2, 2};
        std::cout << candy(ratings) << '\n';
    }

    {
        std::vector<int> ratings = {2, 0, 0, 2};
        std::cout << candy(ratings) << '\n';
    }

    {
        std::vector<int> ratings = {2, 1, 3, 2};
        std::cout << candy(ratings) << '\n';
    }

    return 0;
}