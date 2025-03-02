#include <cassert>
#include <string>

std::string clearDigits(std::string s)
{
  std::string result;
  for (int i = 0; i < s.length(); ++i) {
    if (std::isdigit(s[i]) && !result.empty()) {
      result.pop_back();
    } else {
      result.push_back(s[i]);
    }
  }

  return result;
}

int main()
{
  // 3174. Clear Digits

  assert(clearDigits("abc") == "abc");
  assert(clearDigits("cb34") == "");
  assert(clearDigits("c1b9abv") == "abv");

  return 0;
}
