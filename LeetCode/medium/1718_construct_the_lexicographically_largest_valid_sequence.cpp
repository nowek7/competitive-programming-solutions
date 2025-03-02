#include <cassert>
#include <vector>

bool findSequence(int idx, std::vector<int>& result, std::vector<bool> usedNumbers, int target)
{
  if (idx == result.size()) {
    return true;
  }

  if (result[idx] != -1) {
    return findSequence(idx + 1, result, usedNumbers, target);
  }

  for (int i = target; i >= 1; --i) {
    if (usedNumbers[i]) {
      continue;
    }

    result[idx] = i;
    usedNumbers[i] = true;

    if (i == 1) {
      if (findSequence(idx + 1, result, usedNumbers, target)) {
        return true;
      }
    } else if (idx + i < result.size() && result[idx + i] == -1) {
      result[idx + i] = i;
      if (findSequence(idx + 1, result, usedNumbers, target)) {
        return true;
      }

      result[idx + i] = -1;
    }

    result[idx] = -1;
    usedNumbers[i] = false;
  }

  return false;
}

std::vector<int> constructDistancedSequence(int n)
{
  std::vector<int> result(2 * n - 1, -1);
  std::vector<bool> usedNumbers(n + 1, false);

  findSequence(0, result, usedNumbers, n);

  return result;
}

int main()
{
  // 1718. Construct the Lexicographically Largest Valid Sequence

  {
    int n = 3;
    std::vector<int> expected = {3, 1, 2, 3, 2};
    std::vector<int> result = constructDistancedSequence(n);
    assert(result == expected);
  }

  {
    int n = 5;
    std::vector<int> expected = {5, 3, 1, 4, 3, 5, 2, 4, 2};
    std::vector<int> result = constructDistancedSequence(n);
    assert(result == expected);
  }

  return 0;
}
