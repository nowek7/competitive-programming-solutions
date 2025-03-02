#include <cassert>
#include <iostream>
#include <stack>
#include <string>

std::string removeOccurrences(std::string s, std::string part)
{
  auto found = [](std::stack<char>& chars, const std::string& part) -> bool {
    std::stack<char> tmpChars = chars;
    for (int i = part.length() - 1; i >= 0; --i) {
      if (tmpChars.top() != part[i]) {
        return false;
      }
      tmpChars.pop();
    }

    return true;
  };

  std::stack<char> chars;
  for (auto i = 0; i < s.length(); ++i) {
    chars.push(s[i]);

    if (chars.size() >= part.length() && found(chars, part)) {
      for (int j = 0; j < part.length(); ++j) {
        chars.pop();
      }
    }
  }

  std::string result;
  while (!chars.empty()) {
    result = chars.top() + result;
    chars.pop();
  }

  return result;
}

int main()
{
  // 1910. Remove All Occurrences of a Substring

  {
    std::string s = "daabcbaabcbc";
    std::string part = "abc";
    assert(removeOccurrences(s, part) == "dab");
  }

  {
    std::string s = "axxxxyyyyb";
    std::string part = "xy";
    assert(removeOccurrences(s, part) == "ab");
  }

  return 0;
}
