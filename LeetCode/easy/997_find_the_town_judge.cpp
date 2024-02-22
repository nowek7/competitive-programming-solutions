#include <cassert>
#include <vector>

int findJudge(int n, std::vector<std::vector<int>>& trust)
{
  std::vector<int> trusting(n + 1, 0);
  std::vector<int> trusted(n + 1, 0);

  for (auto& entry: trust) {
    ++trusting[entry[0]];
    ++trusted[entry[1]];
  }

  int judge = -1;
  for (int i = 1; i < n + 1; ++i) {
    if (trusted[i] == n - 1 && trusting[i] == 0) {
      judge = i;
    }
  }

  return judge;
}

int main()
{
  // 997. Find the Town Judge

  {
    const int n = 2;
    std::vector<std::vector<int>> trust = {
      {1, 2}
    };
    assert(findJudge(n, trust) == 2);
  }

  {
    const int n = 3;
    std::vector<std::vector<int>> trust = {
      {1, 3},
      {2, 3}
    };
    assert(findJudge(n, trust) == 3);
  }

  {
    const int n = 3;
    std::vector<std::vector<int>> trust = {
      {1, 3},
      {2, 3},
      {2, 3}
    };
    assert(findJudge(n, trust) == -1);
  }

  return 0;
}
