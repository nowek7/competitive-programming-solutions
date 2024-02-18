#include <cassert>
#include <cmath>

int numSquares(int n)
{
  while (n % 4 == 0) {
    n /= 4;
  }
  if (n % 8 == 7) {
    return 4;
  }
  auto isSquare = [](int n) {
    auto square = std::sqrt(n);
    return static_cast<double>(square) == static_cast<int>(square);
  };
  if (isSquare(n)) {
    return 1;
  }

  double square = std::sqrt(n);
  for (int i = 1; i <= square; ++i) {
    int x = n - i * i;
    if (isSquare(x)) {
      return 2;
    }
  }

  return 3;
}

int main()
{
  // 279. Perfect Squares

  {
    assert(numSquares(3) == 3);
  }

  {
    assert(numSquares(2) == 2);
  }

  return 0;
}
