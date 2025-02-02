#include <iostream>
#include <string>
using namespace std;

int FirstFactorial(int num)
{
  int result = 1;
  for (int i = 1; i <= num; ++i) {
    result *= i;
  }

  return result;
}

int main(void)
{
  cout << FirstFactorial(coderbyteInternalStdinFunction(stdin));
  return 0;
}
