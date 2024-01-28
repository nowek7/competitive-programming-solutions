#include <cassert>
#include <vector>

std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img)
{
  const int m = img.size();
  const int n = img[0].size();
  std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

  auto computeValueFilter = [&img, &m, &n](int rowIdx, int colIdx) {
    int sum = 0;
    int counter = 0;
    if (rowIdx > 0) {
      if (colIdx > 0) {
        sum += img[rowIdx - 1][colIdx - 1];
        ++counter;
      }
      {
        sum += img[rowIdx - 1][colIdx];
        ++counter;
      }
      if (colIdx < n - 1) {
        sum += img[rowIdx - 1][colIdx + 1];
        ++counter;
      }
    }
    if (colIdx > 0) {
      sum += img[rowIdx][colIdx - 1];
      ++counter;
    }
    {
      sum += img[rowIdx][colIdx];
      ++counter;
    }
    if (colIdx < n - 1) {
      sum += img[rowIdx][colIdx + 1];
      ++counter;
    }

    if (rowIdx < m - 1) {
      if (colIdx > 0) {
        sum += img[rowIdx + 1][colIdx - 1];
        ++counter;
      }
      {
        sum += img[rowIdx + 1][colIdx];
        ++counter;
      }
      if (colIdx < n - 1) {
        sum += img[rowIdx + 1][colIdx + 1];
        ++counter;
      }
    }

    return sum / counter;
  };

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      result[i][j] = computeValueFilter(i, j);
    }
  }

  return result;
}

int main()
{
  // 661. Image Smoother
  {
    std::vector<std::vector<int>> img = {
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1}
    };
    std::vector<std::vector<int>> expected = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0}
    };
    assert(imageSmoother(img) == expected);
  }
  return 0;
}
