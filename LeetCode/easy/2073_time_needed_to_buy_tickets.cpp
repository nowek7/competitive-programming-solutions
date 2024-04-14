#include <cassert>
#include <iostream>
#include <vector>

int timeRequiredToBuy(std::vector<int>& tickets, int k)
{
  int amount = 0;
  for (int i = 0; i <= k; ++i) {
    amount += std::min(tickets[k], tickets[i]);
  }

  for (int i = k + 1; i < tickets.size(); ++i) {
    amount += std::min(tickets[k] - 1, tickets[i]);
  }

  return amount;
}

int main()
{
  // 2073. Time Needed to Buy Tickets

  {
    std::vector<int> tickets = {2, 3, 2};
    int k = 2;
    assert(timeRequiredToBuy(tickets, k) == 6);
  }

  {
    std::vector<int> tickets = {5, 1, 1, 1};
    int k = 0;
    assert(timeRequiredToBuy(tickets, k) == 8);
  }

  {
    std::vector<int> tickets = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int k = 8;
    assert(timeRequiredToBuy(tickets, k) == 81);
  }

  {
    std::vector<int> tickets = {84, 49, 5, 24, 70, 77, 87, 8};
    int k = 3;
    assert(timeRequiredToBuy(tickets, k) == 154);
  }

  {
    std::vector<int> tickets = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int k = 4;
    assert(timeRequiredToBuy(tickets, k) == 51);
  }

  {
    std::vector<int> tickets = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int k = 4;
    assert(timeRequiredToBuy(tickets, k) == 95);
  }

  {
    std::vector<int> tickets = {21, 90, 85, 11, 50, 72, 11, 74, 14, 96, 55, 87, 45, 12, 100, 81, 76, 73, 30, 54,
                                84, 9,  51, 69, 74, 91, 60, 45, 42, 67, 17, 46, 47, 60, 45,  7,  88, 28, 99, 13,
                                41, 53, 72, 50, 24, 60, 52, 20, 8,  42, 51, 95, 68, 43, 26,  56, 68, 14, 91, 42,
                                93, 14, 46, 95, 33, 67, 99, 99, 7,  59, 46, 15, 7,  11, 60,  97, 56, 12, 13, 88,
                                70, 98, 5,  7,  16, 32, 19, 16, 9,  46, 57, 66, 25, 60, 30,  67, 22, 33, 18, 21};
    int k = 15;
    assert(timeRequiredToBuy(tickets, k) == 4659);
  }

  return 0;
}