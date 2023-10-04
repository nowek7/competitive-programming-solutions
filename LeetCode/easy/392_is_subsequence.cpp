#include <iostream>
#include <string>

bool isSubsequence(std::string s, std::string t)
{
  if (s.empty()) {
    return true;
  }

  if (s.size() > t.size()) {
    return false;
  }

  int j = 0;
  for (int i = 0; i < t.size() && j < s.size(); ++i) {
    if (t[i] == s[j]) {
      ++j;
    }
  }

  return j == s.size();
}

int main()
{
  // 392. Is Subsequence
  {
    std::cout << isSubsequence("", "") << '\n';
  }

  {
    std::cout << isSubsequence("axc", "ahbgdc") << '\n';
  }

  {
    std::cout << isSubsequence("abc", "ahbgdc") << '\n';
  }

  return 0;
}