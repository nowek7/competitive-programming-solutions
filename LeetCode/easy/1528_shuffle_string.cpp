#include <algorithm>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

std::string restoreString(std::string text, std::vector<int>& indices)
{
  assert(text.size() == indices.size());

  for (auto i = 0; i < text.size(); ++i)
  {
    int& movedIdx = indices.at(i);
    while (i != movedIdx)
    {
      std::swap(text.at(i), text.at(movedIdx));
      std::swap(movedIdx, indices.at(movedIdx));
    }
  }

  return text;
}

std::string restoreString_v2(std::string text, std::vector<int>& indices)
{
  assert(text.size() == indices.size());

  std::string tmp = text;
  for (auto i = 0; i < text.size(); ++i)
  {
    int& movedIdx = indices.at(i);
    if (i != movedIdx)
    {
      tmp[i] = text[movedIdx];
    }
  }

  return text;
}

int main()
{
  // 1528. Shuffle string
  {
    std::string text{"abc"};
    std::vector<int> indices = {0, 1, 2};

    assert("abc" == restoreString(text, indices));
  }

  {
    std::string text{"abc"};
    std::vector<int> indices = {2, 0, 1};

    assert("bca" == restoreString(text, indices));
  }

  return 0;
}
