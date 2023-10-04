#include <algorithm>
#include <iostream>
#include <string>

void reverseString(std::vector<char>& s)
{
  std::reverse(s.begin(), s.end());
}

void reverseString_v2(std::vector<char>& s)
{
  for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
    std::swap(s[i], s[j]);
  }
}

int main()
{
  // 344. Reverse string
  {
    std::vector<char> text = {'h', 'e', 'l', 'l', 'o'};
    reverseString(text);
  }

  {
    std::vector<char> text = {'H', 'a', 'n', 'n', 'a', 'h'};
    reverseString(text);
  }

  return 0;
}