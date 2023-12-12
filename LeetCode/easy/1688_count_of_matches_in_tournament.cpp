#include <cassert>

int numberOfMatches(int n)
{
  int result = 0;
  while (n > 1) {
    if (n & 1) {
      result += (n - 1) * 0.5;
      n = (n - 1) * 0.5 + 1;
    } else {
      result += (n * 0.5);
      n *= 0.5;
    }
  }
  return result;
}

int numberOfMatches_v2(int n)
{
  return n - 1;
}

int main()
{
  // 1688. Count of Matches in Tournament
  assert(numberOfMatches(7) == 6);
  assert(numberOfMatches(14) == 13);
  assert(numberOfMatches(30) == 29);
  assert(numberOfMatches(50) == 49);

  return 0;
}