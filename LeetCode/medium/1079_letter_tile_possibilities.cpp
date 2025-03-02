#include <array>
#include <cassert>
#include <string>

int find(std::array<char, 26>& frequency)
{
  int count = 0;
  for (int i = 0; i < 26; ++i) {
    if (frequency[i] == 0) {
      continue;
    }

    ++count;
    --frequency[i];
    count += find(frequency);
    ++frequency[i];
  }

  return count;
}

int numTilePossibilities(std::string tiles)
{
  std::array<char, 26> frequency {0};
  for (auto c: tiles) {
    ++frequency[c - 'A'];
  }

  return find(frequency);
}

int main()
{
  // 1079. Letter Tile Possibilities

  {
    std::string s = "AAB";
    assert(numTilePossibilities(s) == 8);
  }

  {
    std::string s = "AAABBC";
    assert(numTilePossibilities(s) == 188);
  }

  {
    std::string s = "V";
    assert(numTilePossibilities(s) == 1);
  }

  return 0;
}
