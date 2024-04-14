#include <algorithm>
#include <cassert>
#include <stack>
#include <string>

std::string removeKdigits(std::string num, int k)
{
  if (num.size() == k) {
    return "0";
  }

  std::stack<char> heap;
  for (auto c: num) {
    while (k > 0 && !heap.empty() && heap.top() > c) {
      heap.pop();
      --k;
    }
    heap.push(c);
  }

  while (!heap.empty() && k > 0) {
    heap.pop();
    --k;
  }

  std::string result {};
  while (!heap.empty()) {
    result.push_back(heap.top());
    heap.pop();
  }
  std::reverse(result.begin(), result.end());

  const int pos = result.find_first_not_of("0");
  return pos == std::string::npos ? "0" : result.substr(pos);
}

int main()
{
  // 402. Remove K Digits

  {
    std::string num = "1432219";
    assert(removeKdigits(num, 3) == "1219");
  }

  {
    std::string num = "1432219";
    assert(removeKdigits(num, 1) == "132219");
  }

  {
    std::string num = "10200";
    assert(removeKdigits(num, 2) == "0");
  }

  {
    std::string num = "10200";
    assert(removeKdigits(num, 1) == "200");
  }

  {
    std::string num = "100";
    assert(removeKdigits(num, 3) == "0");
  }

  {
    std::string num = "1002022";
    assert(removeKdigits(num, 2) == "22");
  }

  {
    std::string num = "100202290";
    assert(removeKdigits(num, 4) == "20");
  }

  return 0;
}