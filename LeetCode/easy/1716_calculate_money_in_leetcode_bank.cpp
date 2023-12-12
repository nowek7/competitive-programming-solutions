#include <cassert>

int totalMoney(int n)
{
  const int sumFromFirstWeek = 28;
  int numWeeks = n / 7;
  int numDays = n % 7;
  int total = sumFromFirstWeek * numWeeks;
  if (numWeeks > 0) {
    total += (numWeeks * 7) * (numWeeks - 1) * 0.5;
  }
  total += (numWeeks + 1 + numWeeks + numDays) * 0.5 * numDays;
  return total;
}

int main()
{
  // 1716. Calculate Money in Leetcode Bank
  assert(totalMoney(1) == 1);
  assert(totalMoney(2) == 3);
  assert(totalMoney(7) == 28);
  assert(totalMoney(10) == 37);
  assert(totalMoney(20) == 96);
  assert(totalMoney(999) == 74778);
  assert(totalMoney(1000) == 74926);

  return 0;
}