#include <cassert>
#include <string>
#include <vector>

std::string firstPalindrome(std::vector<std::string>& words)
{
  auto isPalindrome = [](const std::string& s) -> bool {
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  };

  for (auto s: words) {
    if (isPalindrome(s)) {
      return s;
    }
  }
  return "";
}

int main()
{
  // 2108. Find First Palindromic String in the Array
  {
    std::vector<std::string> words = {"abc", "car", "ada", "racecar", "cool"};
    assert(firstPalindrome(words) == "ada");
  }

  {
    std::vector<std::string> words = {"notapalindrome", "racecar"};
    assert(firstPalindrome(words) == "racecar");
  }

  {
    std::vector<std::string> words = {"def", "ghi"};
    assert(firstPalindrome(words) == "");
  }

  return 0;
}
