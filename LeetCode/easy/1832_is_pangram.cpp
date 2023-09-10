#include <bitset>
#include <iostream>
#include <string>

constexpr int ASCII_CODE_A = 97;
constexpr int ALPHABET_SIZE = 26;

bool checkIfPangram(const std::string& sentence)
{
  std::bitset<ALPHABET_SIZE> occurrences;
  for (char c: sentence)
  {
    occurrences[c - ASCII_CODE_A] = true;
  }

  return occurrences.all();
}

int main()
{
  // 1832. Check if the Sentence Is Pangram
  {
    std::string text = "thequickbrownfoxjumpsoverthelazydog";
    std::cout << std::boolalpha << checkIfPangram(text) << '\n';
  }

  return 0;
}