#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int lengthOfLongestSubstring(std::string s)
{
  if (s.length() <= 1) {
    return s.length();
  }

  std::unordered_set<char> word;
  int maxLength = 0;

  int start = 0;
  int end = 0;
  while (end < s.size()) {
    if (word.count(s.at(end)) == 0) {
      word.insert(s.at(end));
      maxLength = maxLength < word.size() ? word.size() : maxLength;
      ++end;
    } else {
      word.erase(s.at(start));
      ++start;
    }
  }

  return maxLength;
}

int lengthOfLongestSubstring_v2(std::string s)
{
  if (s.length() <= 1) {
    return s.length();
  }

  int maxLength = 0;
  int start = -1;
  std::vector<int> dict(256, -1);
  for (int i = 0; i < s.size(); ++i) {
    if (dict.at(s.at(i)) > start) {
      start = dict.at(s.at(i));
    }

    dict[s.at(i)] = i;
    maxLength = maxLength < (i - start) ? (i - start) : maxLength;
  }

  return maxLength;
}

int main()
{
  // 3. Longest Substring Without Repeating Characters
  {
    std::string s = "abcabcbb";
    std::cout << lengthOfLongestSubstring_v2(s) << '\n';
  }

  {
    std::string s = "pwwkew";
    std::cout << lengthOfLongestSubstring(s) << '\n';
  }

  {
    std::string s = "abcdefghi";
    std::cout << lengthOfLongestSubstring(s) << '\n';
  }

  {
    std::string s = "bbbbb";
    std::cout << lengthOfLongestSubstring(s) << '\n';
  }

  {
    std::string s = "au";
    std::cout << lengthOfLongestSubstring_v2(s) << '\n';
  }

  {
    std::string s = "aab";
    std::cout << lengthOfLongestSubstring_v2(s) << '\n';
  }

  return 0;
}