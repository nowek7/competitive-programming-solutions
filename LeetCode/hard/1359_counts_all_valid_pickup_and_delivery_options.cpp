#include <cassert>

int countOrders(int n)
{
  const int mod = 1000000007;
  long long count = 1;

  for (int i = 1; i <= n; ++i) {
    count = count * i % mod;
  }

  for (int i = 1; i <= 2 * n; i += 2) {
    count = count * i % mod;
  }

  return count;
}

int main()
{
  // 1359. Count All Valid Pickup and Delivery Options

  assert(countOrders(1) == 1);
  assert(countOrders(2) == 6);
  assert(countOrders(3) == 90);

  return 0;
}
