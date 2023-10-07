#include <array>
#include <iostream>
#include <string>

char findTheDifference(std::string s, std::string t)
{
  std::array<int, 26> alphabet1 {0};
  std::array<int, 26> alphabet2 {0};
  for (char c: s) {
    alphabet1[c - 'a']++;
  }
  for (char c: t) {
    alphabet2[c - 'a']++;
  }

  int i = 0;
  while (alphabet1[i] == alphabet2[i]) {
    ++i;
  }

  return i + 'a';
}

int main()
{
  // 389. Find the Difference

  std::cout << findTheDifference("", "t") << '\n';
  std::cout << findTheDifference("aabcde", "aabcdee") << '\n';
  return 0;
}
