#include <cassert>
#include <unordered_set>
#include <vector>

std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B)
{
  assert(A.size() == B.size());

  const int n = A.size();
  std::vector<int> result(n, 0);
  if (A[0] == B[0]) {
    result[0] = 1;
  }

  std::unordered_set<int> numbersA = {A[0]};
  std::unordered_set<int> numbersB = {B[0]};
  for (auto i = 1; i < n; ++i) {
    if (A[i] == B[i]) {
      ++result[i];
    } else {
      if (numbersA.count(B[i]) == 1) {
        ++result[i];
      }

      if (numbersB.count(A[i]) == 1) {
        ++result[i];
      }
    }
    result[i] += result[i - 1];

    numbersA.insert(A[i]);
    numbersB.insert(B[i]);
  }

  return result;
}

int main()
{
  // 2657. Find the Prefix Common Array of Two Arrays

  {
    std::vector<int> A = {1, 3, 2, 4};
    std::vector<int> B = {3, 1, 2, 4};
    std::vector<int> expected = {0, 2, 3, 4};
    auto result = findThePrefixCommonArray(A, B);
    assert(result == expected);
  }

  {
    std::vector<int> A = {2, 3, 1};
    std::vector<int> B = {3, 1, 2};
    std::vector<int> expected = {0, 1, 3};
    auto result = findThePrefixCommonArray(A, B);
    assert(result == expected);
  }

  return 0;
}
