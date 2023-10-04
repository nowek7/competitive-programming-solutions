#include <iostream>
#include <vector>

bool isPalindrome(int x)
{
  if (x < 0) {
    return false;
  }

  int revision = x;
  int reverse = 0;
  while (x != 0) {
    reverse = (reverse * 10) + (x % 10);
    x /= 10;
  }

  return reverse == revision;
}

bool isPalindrome_v2(int x)
{
  if (x < 0) {
    return false;
  } else if (x < 10) {
    return true;
  } else {
    std::vector<int> digits;
    int rem;
    while (x > 0) {
      rem = x % 10;
      x = (x - rem) / 10;
      digits.push_back(rem);
    }

    for (int i = 0, j = (digits.size() - 1); i < j; ++i, --j) {
      if (digits.at(i) != digits.at(j)) {
        return false;
      }
    }

    return true;
  }
}

int main()
{
  // 9. Palindrome Number
  {
    int x = -1;
    std::cout << std::boolalpha << isPalindrome(x) << '\n';
  }

  {
    int x = 0;
    std::cout << std::boolalpha << isPalindrome(x) << '\n';
  }

  {
    int x = 2;
    std::cout << std::boolalpha << isPalindrome(x) << '\n';
  }

  {
    int x = 989;
    std::cout << std::boolalpha << isPalindrome(x) << '\n';
  }

  {
    int x = 1001;
    std::cout << std::boolalpha << isPalindrome(x) << '\n';
  }

  {
    int x = 52125;
    std::cout << std::boolalpha << isPalindrome(x) << '\n';
  }

  {
    int x = 52126;
    std::cout << std::boolalpha << isPalindrome(x) << '\n';
  }

  return 0;
}