#include <iostream>
#include <numeric>
#include <vector>

double champagneTower(int poured, int query_row, int query_glass)
{
  std::vector<std::vector<double>> storage(query_row + 1, std::vector<double>(query_row + 1));
  storage[0][0] = poured;

  for (int i = 0; i < query_row; ++i) {
    for (int j = 0; j <= i; ++j) {
      double overflow = std::max(0.0, (storage[i][j] - 1)) / 2;
      storage[i + 1][j] += overflow;
      storage[i + 1][j + 1] += overflow;
    }
  }
  return std::min(1.0, storage[query_row][query_glass]);
}

int main()
{
  std::cout << champagneTower(1, 1, 1) << '\n';
  std::cout << champagneTower(2, 1, 1) << '\n';
  std::cout << champagneTower(100000009, 33, 17) << '\n';

  return 0;
}