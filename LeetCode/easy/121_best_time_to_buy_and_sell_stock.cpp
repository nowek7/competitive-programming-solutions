#include <vector>
#include <cmath>

#include <iostream>

int maxProfit(std::vector<int>& prices)
{
    if (prices.size() < 2) {
        return 0;
    } else {
        int maxProfit = 0;
        for (int i = prices.size() - 2, sellPrice = prices.back(); i >= 0; --i) {
            sellPrice = std::max(sellPrice, prices.at(i));
            maxProfit = std::max(maxProfit, sellPrice - prices.at(i));
            // const int profit = sellPrice - prices.at(i);
            // if (sellPrice < prices.at(i)) {
            //     sellPrice = prices.at(i);
            // } else if (profit > maxProfit) {
            //     maxProfit = profit;
            // }
        }

        return std::max(maxProfit, 0);
    }
}

int maxProfit_v2(std::vector<int>& prices)
{
    if (prices.size() < 2) {
        return 0;
    } else {
        int maxProfit = 0;
        for (int i = prices.size() - 2, sellPrice = prices.back(); i >= 0; --i) {
            const int profit = sellPrice - prices.at(i);
            if (sellPrice < prices.at(i)) {
                sellPrice = prices.at(i);
            } else if (profit > maxProfit) {
                maxProfit = profit;
            }
        }

        return std::max(maxProfit, 0);
    }
}

int main()
{
    // 121. Best Time to Buy and Sell Stock
    {
        std::vector<int> prices = {1};
        std::cout << maxProfit(prices) << " = max profit" << '\n';
    }

    {
        std::vector<int> prices = {1, 2};
        std::cout << maxProfit(prices) << " = max profit" << '\n';
    }

    {
        std::vector<int> prices = {7, 1, 5, 3, 6, 4};
        std::cout << maxProfit(prices) << " = max profit" << '\n';
    }

    {
        std::vector<int> prices = {7, 6, 4, 3, 1};
        std::cout << maxProfit(prices) << " = max profit" << '\n';
    }

    {
        std::vector<int> prices = {7, 8, 5, 6, 4, 9};
        std::cout << maxProfit(prices) << " = max profit" << '\n';
    }

    {
        std::vector<int> prices = {7, 8, 1, 9, 5};
        std::cout << maxProfit(prices) << " = max profit" << '\n';
    }

    {
        std::vector<int> prices = {7, 8, 1, 9, 15};
        std::cout << maxProfit(prices) << " = max profit" << '\n';
    }

    return 0;
}