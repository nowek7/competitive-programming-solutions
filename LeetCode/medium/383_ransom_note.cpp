#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool canConstruct(std::string ransomNote, std::string magazine)
{
  std::unordered_map<char, int> dictionary;
  for (char c: magazine) {
    dictionary[c]++;
  }

  for (char c: ransomNote) {
    if (dictionary.count(c) && dictionary[c]) {
      dictionary[c]--;
    } else {
      return false;
    }
  }

  return true;
}

bool canConstruct_v2(std::string ransomNote, std::string magazine)
{
  std::vector<int> dictionary(26, 0);
  for (char c: magazine) {
    dictionary[c - 'a']++;
  }

  for (char c: ransomNote) {
    if (dictionary.at(c - 'a')) {
      dictionary[c - 'a']--;
    } else {
      return false;
    }
  }

  return true;
}

int main()
{
  // 383. Ransom Note
  {
    std::string ransomNote = "aa";
    std::string magazine = "ab";
    assert(canConstruct(ransomNote, magazine) == false);
  }

  {
    std::string ransomNote = "aa";
    std::string magazine = "aab";
    assert(canConstruct_v2(ransomNote, magazine) == true);
  }

  return 0;
}
