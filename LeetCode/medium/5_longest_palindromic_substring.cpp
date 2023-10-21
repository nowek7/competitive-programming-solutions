#include <cmath>
#include <iostream>
#include <string>

std::string longestPalindrome(std::string s)
{
  const int len = s.length();

  int longestLen = 0;
  std::string palindrome;
  for (int idx = 0; idx < len; ++idx) {
    for (int shift = 0; idx - shift >= 0 && idx + shift < len; ++shift) {
      if (s[idx - shift] != s[idx + shift]) {
        break;
      }

      int tmpLen = 2 * shift + 1;
      if (tmpLen > longestLen) {
        longestLen = tmpLen;
        palindrome = s.substr(idx - shift, longestLen);
      }
    }
  }

  for (int idx = 0; idx < len - 1; ++idx) {
    for (int shift = 1; idx - shift + 1 >= 0 && idx + shift < len; ++shift) {
      if (s[idx - shift + 1] != s[idx + shift]) {
        break;
      }

      int tmpLen = 2 * shift;
      if (tmpLen > longestLen) {
        longestLen = tmpLen;
        palindrome = s.substr(idx - shift + 1, longestLen);
      }
    }
  }

  return palindrome;
}

int main()
{
  // 5. Longest Palindromic Substring
  {
    std::string s = "babad";
    std::cout << s << " -> " << longestPalindrome(s) << '\n';
  }

  {
    std::string s = "bb";
    std::cout << s << " -> " << longestPalindrome(s) << '\n';
  }

  {
    std::string s = "cacac";
    std::cout << s << " -> " << longestPalindrome(s) << '\n';
  }

  {
    std::string s = "cacscac";
    std::cout << s << " -> " << longestPalindrome(s) << '\n';
  }

  {
    std::string s = "cfcacac";
    std::cout << s << " -> " << longestPalindrome(s) << '\n';
  }

  {
    std::string s = "cbbd";
    std::cout << s << " -> " << longestPalindrome(s) << '\n';
  }

  {
    std::string s = "acacscscaad";
    std::cout << s << " -> " << longestPalindrome(s) << '\n';
  }

  return 0;
}