#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

std::string reverseWords(std::string s)
{
  if (s.size() == 1) {
    return s;
  }

  std::string result;
  std::string word;
  for (int i = 0; i < s.size(); ++i) {
    if (std::isspace(s[i])) {
      std::reverse(word.begin(), word.end());
      result += word + " ";
      word.clear();
    } else {
      word += s[i];
    }
  }

  if (!word.empty()) {
    std::reverse(word.begin(), word.end());
    result += word;
  }

  assert(result.size() == s.size());

  return result;
}

std::string reverseWords_v2(std::string s)
{
  if (s.size() == 1) {
    return s;
  }

  int start = 0;
  auto pos = s.find(" ", start);
  while (pos != std::string::npos) {
    std::reverse(s.begin() + start, s.begin() + pos);
    start = pos + 1;
    pos = s.find(" ", start);
  }

  std::reverse(s.begin() + start, s.end());

  return s;
}

int main()
{
  // 557. Reverse Words in a String III
  {
    std::string s {"Let's take LeetCode contest"};
    std::cout << reverseWords(s) << '\n';
  }

  {
    std::string s {"Let's take LeetCode contest"};
    std::cout << reverseWords_v2(s) << '\n';
  }

  return 0;
}