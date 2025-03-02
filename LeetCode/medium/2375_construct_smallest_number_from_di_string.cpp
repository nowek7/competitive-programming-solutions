#include <cassert>
#include <stack>
#include <string>

std::string smallestNumber(std::string pattern)
{
  std::string result;

  std::stack<int> heap;
  for (auto i = 0; i <= pattern.size(); ++i) {
    heap.push(i + 1);
    if (pattern[i] == 'I' || i == pattern.size()) {
      while (!heap.empty()) {
        result += std::to_string(heap.top());
        heap.pop();
      }
    }
  }

  return result;
}

int main()
{
  // 2375. Construct Smallest Number From DI String

  {
    std::string pattern = "IIIDIDDD";
    assert(smallestNumber(pattern) == "123549876");
  }

  {
    std::string pattern = "DDD";
    assert(smallestNumber(pattern) == "4321");
  }

  return 0;
}
