#include <cmath>
#include <iostream>

int integerBreak(int n)
{
  int maxProd = 1;
  for (int numSplit = 2; numSplit <= n; ++numSplit) {
    int r = n % numSplit;
    int diff = n / numSplit;
    if (diff == 1 && r < 2) {
      maxProd = std::max(maxProd, diff + r);
      continue;
    }

    int prod = 1;
    for (int i = 0; i < numSplit; ++i) {
      if (r > 0) {
        prod *= (diff + 1);
        --r;
      } else {
        prod *= diff;
      }
    }
    maxProd = std::max(maxProd, prod);
  }

  return maxProd;
}

int main()
{
  // 343. Integer Break

  for (int i = 2; i <= 12; ++i) {
    auto result = integerBreak(i);
    std::cout << i << " -> " << result << '\n';
  }

  return 0;
}
