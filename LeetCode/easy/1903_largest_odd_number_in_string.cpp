#include <iostream>
#include <string>

std::string largestOddNumber(std::string num)
{
  for (int i = num.size() - 1; i >= 0; --i) {
    if ((num[i] - '0') & 1 == 1) {
      return num.substr(0, i + 1);
    }
  }

  return "";
}

int main()
{
  // 1903. Largest Odd Number in String

  {
    std::string s = "52";
    std::cout << largestOddNumber(s) << '\n';
  }

  {
    std::string s = "4206";
    std::cout << largestOddNumber(s) << '\n';
  }

  {
    std::string s = "35427";
    std::cout << largestOddNumber(s) << '\n';
  }

  {
    std::string s = "13542734";
    std::cout << largestOddNumber(s) << '\n';
  }

  return 0;
}