#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
  std::string prefix = strs.front();
  for (int i = 1; i < strs.size(); ++i) {
    const std::string& str = strs.at(i);
    const int length = std::min(prefix.size(), str.size());

    int j = 0;
    while (j < length && prefix.at(j) == str.at(j)) {
      ++j;
    }
    prefix = prefix.substr(0, j);
  }

  return prefix;
}

int main()
{
  // 14. Longest Common Prefix
  {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << longestCommonPrefix(strs) << '\n';
  }

  {
    std::vector<std::string> strs = {"dog", "racecar", "car"};
    std::cout << longestCommonPrefix(strs) << '\n';
  }

  return 0;
}