#include <algorithm>
#include <string>

#include <iostream>

std::string toLowerCase(std::string text)
{
  std::transform(text.begin(), text.end(), text.begin(), ::tolower);
  return text;
}

int main()
{
  // 709. To Lower Case
  {
    std::string text{"HeLlO"};
    std::cout << toLowerCase(text) << '\n';
  }

  return 0;
}