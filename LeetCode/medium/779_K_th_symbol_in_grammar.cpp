#include <cassert>
#include <iostream>

int kthGrammar(int n, int k)
{
  if (n == 1) {
    return 0;
  }

  const int length = 1 << (n - 2);
  if (k <= length) {
    return kthGrammar(n - 1, k);
  } else {
    return 1 - kthGrammar(n - 1, k - length);
  }
}

int main()
{
  // 779. K-th Symbol in Grammar

  assert(kthGrammar(1, 1) == 0);
  assert(kthGrammar(2, 1) == 0);
  assert(kthGrammar(2, 2) == 1);
  assert(kthGrammar(5, 4) == 0);
  assert(kthGrammar(3, 2) == 1);
  assert(kthGrammar(4, 5) == 1);

  return 0;
}
