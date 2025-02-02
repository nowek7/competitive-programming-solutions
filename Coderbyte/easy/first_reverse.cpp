#include <algorithm>
#include <iostream>
#include <string>

std::string FirstReverse(std::string str)
{
  std::reverse(str.begin(), str.end());
  return str;
}

int main()
{
  std::cout << FirstReverse(coderbyteInternalStdinFunction(stdin));
  return 0;
}
