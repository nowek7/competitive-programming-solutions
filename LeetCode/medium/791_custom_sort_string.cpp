#include <array>
#include <cassert>
#include <string>

std::string customSortString(std::string order, std::string s)
{
  std::array<int, 26> store {0};
  for (auto c: s) {
    ++store[c - 'a'];
  }

  std::string result;
  for (auto c: order) {
    while (store[c - 'a'] > 0) {
      result += c;
      --store[c - 'a'];
    }
  }

  for (int i = 0; i < 26; ++i) {
    while (store[i] > 0) {
      result += static_cast<char>(i + 'a');
      --store[i];
    }
  }

  return result;
}

int main()
{
  // 791. Custom Sort String

  {
    std::string order = "cba";
    std::string s = "abcd";
    std::string expected = "cbad";
    assert(customSortString(order, s) == expected);
  }

  {
    std::string order = "kqep";
    std::string s = "pekeq";
    std::string expected = "kqeep";
    assert(customSortString(order, s) == expected);
  }

  {
    std::string order = "hucw";
    std::string s =
      "utzoampdgkalexslxoqfkdjoczajxtuhqyxvlfatmptqdsochtdzgypsfkgqwbgqbcamdqnqztaqhqanirikahtmalzqjjxtqfnh";
    std::string expected =
      "hhhhhuucccwaaaaaaaaabbdddddeffffggggiijjjjkkkkllllmmmmnnnoooopppqqqqqqqqqqqrsssttttttttvxxxxxyyzzzzz";
    assert(customSortString(order, s) == expected);
  }

  return 0;
}