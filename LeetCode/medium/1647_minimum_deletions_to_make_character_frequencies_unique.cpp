#include <string>
#include <unordered_set>
#include <iostream>

int minDeletions(std::string s)
{
  int frequencies[26] = { 0 };
  for (char c: s) {
    frequencies[c - 'a']++;
  }

  int moves = 0;
  std::unordered_set<int> uniqueFrequencies;
  for (auto freq: frequencies) {
    if (freq == 0) {
      continue;
    }
    while (uniqueFrequencies.count(freq)) {
      --freq;
      ++moves;
    }

    if (freq > 0) {
      uniqueFrequencies.insert(freq);
    }
  }

  return moves;
}

int minDeletions_v2(std::string s)
{
  int frequencies[26] = { 0 };
  for (char c: s) {
    frequencies[c - 'a']++;
  }

  int count = 0;
  for (int i = 0; i < 26; ++i) {
    if (frequencies[i] == 0) {
      continue;
    }
    for (int j = 0; j < 26; ++j) {
      if (i != j && frequencies[i] == frequencies[j]) {
        count++;
        frequencies[i]--;
        i--;
        break;
      }
    }
  }

  return count;
}

int main()
{
  // 1647. Minimum Deletions to Make Character Frequencies Unique
  {
    std::string s = "aab";
    std::cout << minDeletions_v2(s) << '\n';
  }

  {
    std::string s = "aaabbbcc";
    std::cout << minDeletions_v2(s) << '\n';
  }

  {
    std::string s = "ceabaacb";
    std::cout << minDeletions_v2(s) << '\n';
  }

  return 0;
}