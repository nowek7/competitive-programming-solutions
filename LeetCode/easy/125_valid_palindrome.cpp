#include <assert.h>
#include <iostream>
#include <string>

bool isPalindrome(std::string s)
{
  const int len = s.length();
  if (s.empty() || len == 1) {
    return true;
  }

  for (int i = 0, j = len - 1; i <= j;) {
    if (!static_cast<bool>(std::isalnum(s[i]))) {
      i++;
    } else if (!static_cast<bool>(std::isalnum(s[j]))) {
      j--;
    } else if (std::tolower(s[i]) != std::tolower(s[j])) {
      return false;
    } else {
      i++;
      j--;
    }
  }

  return true;
}

int main()
{
  // 125. Valid palindrome
  {
    std::string text = "A man, a plan, a canal: Panama";
    assert(isPalindrome(text) == true);
  }

  {
    std::string text = "race a car";
    assert(isPalindrome(text) == false);
  }

  {
    std::string text = " ";
    assert(isPalindrome(text) == true);
  }

  return 0;
}