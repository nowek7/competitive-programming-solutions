#include <cassert>
#include <cmath>

int poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
  int i = 0;
  const int repeats = minutesToTest / minutesToDie;
  while (std::pow(repeats + 1, i) < buckets) {
    ++i;
  }

  return i;
}

int main()
{
  assert(poorPigs(4, 15, 15) == 2);
  assert(poorPigs(4, 15, 30) == 2);
  assert(poorPigs(16, 15, 30) == 3);

  return 0;
}
