#include <iostream>
#include <vector>

std::vector<int> countBits(int n)
{
  std::vector<int> result;
  for (int i = 0; i <= n; ++i) {
    result.push_back(__builtin_popcount(i));
  }

  return result;
}

std::vector<int> countBits_v2(int n)
{
  std::vector<int> result = {0};
  for (int i = 1; i <= n; ++i) {
    result.push_back((i % 2) + result.at(i * 0.5));
  }

  return result;
}

int main()
{
  {
    for (auto&& entry: countBits(16)) {
      std::cout << entry << '\n';
    }
  }

  std::cout << "-----------------" << '\n';

  {
    auto results = countBits_v2(16);
    for (auto i = 0; i < results.size(); ++i) {
      std::cout << i << " ---> " << results.at(i) << '\n';
    }
  }

  return 0;
}