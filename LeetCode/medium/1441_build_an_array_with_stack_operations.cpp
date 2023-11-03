#include <cassert>
#include <string>
#include <vector>

std::vector<std::string> buildArray(std::vector<int>& target, int n)
{
  const std::string pushText = "Push";
  const std::string popText = "Pop";

  std::vector<std::string> result;
  for (int i = 1, j = 0; i <= n && j < target.size(); ++i) {
    if (i < target[j]) {
      result.push_back(pushText);
      result.push_back(popText);
    } else {
      result.push_back(pushText);
      ++j;
    }
  }

  return result;
}

int main()
{
  {
    std::vector<int> target = {1, 3};
    int n = 3;
    std::vector<std::string> expected = {"Push", "Push", "Pop", "Push"};
    assert(buildArray(target, n) == expected);
  }

  {
    std::vector<int> target = {1, 2, 3};
    int n = 3;
    std::vector<std::string> expected = {"Push", "Push", "Push"};
    assert(buildArray(target, n) == expected);
  }

  {
    std::vector<int> target = {1, 2};
    int n = 4;
    std::vector<std::string> expected = {"Push", "Push"};
    assert(buildArray(target, n) == expected);
  }

  return 0;
}
