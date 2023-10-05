#include <array>
#include <iostream>
#include <stack>
#include <string>

std::string removeDuplicateLetters(std::string s)
{
  std::stack<char> chars;
  std::array<int, 26> frequency {0};
  std::array<bool, 26> visited {false};

  for (char c: s) {
    ++frequency[c - 'a'];
  }

  std::stack<char> container;
  for (char c: s) {
    --frequency[c - 'a'];

    if (visited[c - 'a']) {
      continue;
    }

    while ((!chars.empty()) && (c < chars.top()) && (frequency[chars.top() - 'a'] > 0)) {
      visited[chars.top() - 'a'] = false;
      chars.pop();
    }

    chars.push(c);
    visited[c - 'a'] = true;
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
  // 316. Remove Duplicate Letters
  {
    std::string s = "bcabc";
    std::cout << removeDuplicateLetters(s) << '\n';
  }

  {
    std::string s = "bcabc";
    std::cout << removeDuplicateLetters(s) << '\n';
  }

  {
    std::string s = "bcabc";
    std::cout << removeDuplicateLetters(s) << '\n';
  }

  return 0;
}
