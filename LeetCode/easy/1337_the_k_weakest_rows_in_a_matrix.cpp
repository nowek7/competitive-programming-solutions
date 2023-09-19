#include <numeric>
#include <queue>
#include <vector>
#include <iostream>

std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k)
{
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>> numSoldiersPerRow;
  for (int i = 0; i < mat.size(); ++i) {
    const int numSoldiers = std::accumulate(mat[i].begin(), mat[i].end(), 0);
    numSoldiersPerRow.push({numSoldiers, i});
  }

  std::vector<int> result(k, 0);
  for (int i = 0; i < k; ++i) {
    result[i] = numSoldiersPerRow.top().second;
    numSoldiersPerRow.pop();
  }
  return result;
}

void printKWeakestRows(const std::vector<int>& rows)
{
  if (!rows.empty()) {
    for (int i = 0; i < rows.size() - 1; ++i) {
      std::cout << rows.at(i) << " ";
    }
    std::cout << *rows.rbegin() << '\n';
  }
}

int main()
{
  // 1337. The K Weakest Rows in a Matrix
  {
    std::vector<std::vector<int>> matrix = {
      { 1,1,0,0,0 },
      { 1,1,1,1,0 },
      { 1,0,0,0,0 },
      { 1,1,0,0,0 },
      { 1,1,1,1,1 },
    };
    auto result = kWeakestRows(matrix, 3);
    printKWeakestRows(result);
  }
}