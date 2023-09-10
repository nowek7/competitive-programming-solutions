#include <algorithm>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> fizzBuzz(int n)
{
  std::vector<std::string> results;
  results.reserve(n);

  for (int i = 1; i <= n; ++i)
  {
    if (i % 3 == 0 && i % 5 == 0)
    {
      results.push_back("FizzBuzz");
    }
    else if (i % 3 == 0)
    {
      results.push_back("Fizz");
    }
    else if (i % 5 == 0)
    {
      results.push_back("Buzz");
    }
    else
    {
      results.push_back(std::to_string(i));
    }
  }

  return results;
}

void printResults(const std::vector<std::string>& results)
{
  for (auto i = 0; i < results.size() - 1; ++i)
  {
    std::cout << results.at(i) << ' ';
  }
  std::cout << *results.rbegin() << '\n';
}

int main()
{
  {
    auto results = fizzBuzz(1);
    printResults(results);
  }

  {
    auto results = fizzBuzz(3);
    printResults(results);
  }

  {
    auto results = fizzBuzz(3);
    printResults(results);
  }

  {
    auto results = fizzBuzz(5);
    printResults(results);
  }

  {
    auto results = fizzBuzz(6);
    printResults(results);
  }

  {
    auto results = fizzBuzz(15);
    printResults(results);
  }

  return 0;
}