#include <iostream>

int fib(int n)
{
  if (n == 0) {
    return 0;
  } else if (n == 1 || n == 2) {
    return 1;
  } else {
    int prev = 1;
    int curr = 1;
    for (int i = 3; i <= n; ++i) {
      int tmp = prev;
      prev = curr;
      curr = prev + tmp;
    }
    return curr;
  }
}

int fib_v2(int n)
{
  if (n == 0) {
    return 0;
  } else if (n == 1 || n == 2) {
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

int main()
{
  // 509. Fibonacci Number
  {
    std::vector<int> nums = {3, 0, 1};
    std::cout << missingNumber(nums) << '\n';
  }

  {
    std::vector<int> nums = {0, 1};
    std::cout << missingNumber(nums) << '\n';
  }

  {
    std::vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << missingNumber(nums) << '\n';
  }

  return 0;
}