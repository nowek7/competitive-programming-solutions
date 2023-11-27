#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>

bool isVowel(char c)
{
  static char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  return std::find(std::begin(vowels), std::end(vowels), std::tolower(c)) != std::end(vowels);
};

std::string sortVowels(std::string s)
{
  auto isVowel = [](char c) {
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    return std::find(std::begin(vowels), std::end(vowels), std::tolower(c)) != std::end(vowels);
  };

  for (int i = 0; i < s.length(); ++i) {
    if (!isVowel(s[i])) {
      continue;
    }

    for (int j = i + 1; j < s.length(); ++j) {
      if (!isVowel(s[j])) {
        continue;
      }
      if (s[i] > s[j]) {
        std::swap(s[i], s[j]);
      }
    }
  }

  return s;
}

std::string sortVowels_v2(std::string s)
{
  std::map<char, int> vowels;
  for (auto c: s) {
    if (isVowel(c)) {
      ++vowels[c];
    }
  }
  int changedIdx = 0;
  for (auto [v, _]: vowels) {
    for (int i = changedIdx; i < s.length() && vowels[v] > 0; ++i) {
      if (!isVowel(s[i])) {
        continue;
      }
      std::cout << s[i] << " | " << vowels[s[i]] << '\n';
      if (vowels[s[i]] > 0) {
        if (s[i] > v) {
          s[i] = v;
          --vowels[v];
          changedIdx = i;
        }
      } else {
        s[i] = v;
        --vowels[v];
        changedIdx = i;
      }
    }
  }

  return s;
}

std::string sortVowels_v3(std::string s)
{
  std::priority_queue<char, std::vector<char>, std::greater<int>> vowels;
  for (auto c: s) {
    if (isVowel(c)) {
      vowels.push(c);
    }
  }

  for (int i = 0; i < s.length(); ++i) {
    if (isVowel(s[i])) {
      s[i] = vowels.top();
      vowels.pop();
    }
  }

  return s;
}

int main()
{
  // 2785. Sort Vowels in a String

  {
    std::string s = "lEetcOde"; // "lEOtcede"
    std::cout << sortVowels(s) << '\n';
  }

  {
    std::string s = "ldasaseE"; // "ldEsasae"
    std::cout << sortVowels(s) << '\n';
  }

  {
    std::string s = "miCHAl"; // mACHil
    std::cout << sortVowels_v3(s) << '\n';
  }

  return 0;
}