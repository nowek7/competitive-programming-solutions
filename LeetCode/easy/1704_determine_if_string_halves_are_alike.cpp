#include <cassert>
#include <string>

bool halvesAreAlike(std::string s)
{
  auto isVowel = [](char c) -> bool {
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  };

  int leftHalfCountOfVowels = 0;
  int rightHalfCountOfVowels = 0;
  for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
    if (isVowel(s[i])) {
      ++leftHalfCountOfVowels;
    }

    if (isVowel(s[j])) {
      ++rightHalfCountOfVowels;
    }
  }

  return leftHalfCountOfVowels == rightHalfCountOfVowels;
}

int main()
{
  // 1704. Determine if String Halves Are Alike

  {
    std::string s = "book";
    assert(halvesAreAlike(s) == true);
  }

  {
    std::string s = "textbook";
    assert(halvesAreAlike(s) == false);
  }

  return 0;
}
