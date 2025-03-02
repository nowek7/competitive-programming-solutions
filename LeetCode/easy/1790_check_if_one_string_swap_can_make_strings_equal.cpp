#include <cassert>
#include <string>
#include <vector>

bool areAlmostEqual(std::string s1, std::string s2)
{
  const int length = s1.length();
  std::vector<int> indices;
  for (int i = 0; i < length; ++i) {
    if (s1[i] != s2[i]) {
      indices.push_back(i);
    }

    if (indices.size() > 2) {
      return false;
    }
  }

  if (indices.empty()) {
    return true;
  }

  if (indices.size() == 1) {
    return false;
  }

  const int firstIdx = indices[0];
  const int secondIdx = indices[1];
  return (s1[firstIdx] == s2[secondIdx]) && (s1[secondIdx] == s2[firstIdx]);
}

int main()
{
  // 1790. Check if One String Swap Can Make Strings Equal

  assert(areAlmostEqual("bank", "kanb") == true);
  assert(areAlmostEqual("attack", "defend") == false);
  assert(areAlmostEqual("kelb", "kelb") == true);
  assert(areAlmostEqual("b", "b") == true);
  assert(areAlmostEqual("b", "k") == false);

  return 0;
}
