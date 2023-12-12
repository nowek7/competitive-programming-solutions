#include <cassert>
#include <string>

std::string largestGoodInteger(std::string num)
{
  std::string maxNum;
  std::string number {num.front()};
  for (int i = 1; i < num.size(); ++i) {
    if (number.back() == num[i]) {
      number += num[i];
      if (number.size() == 3) {
        maxNum = maxNum.empty() ? number : (maxNum.front() - '0' > number.front() - '0' ? maxNum : number);
      }
    } else {
      number = num[i];
    }
  }

  return maxNum;
}

int main()
{
  // 2264. Largest 3-Same-Digit Number in String
  assert(largestGoodInteger("6777133339") == "777");
  assert(largestGoodInteger("2300019") == "000");
  assert(largestGoodInteger("42352338") == "");

  return 0;
}