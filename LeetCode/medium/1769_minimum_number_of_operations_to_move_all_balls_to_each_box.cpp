#include <cassert>
#include <string>
#include <vector>

std::vector<int> minOperations(std::string boxes)
{
  std::vector<int> result(boxes.size(), 0);

  int ballsLeft = 0;
  int movesLeft = 0;
  int ballsRight = 0;
  int movesRight = 0;

  for (auto i = 0; i < boxes.size(); ++i) {
    result[i] += movesLeft;
    ballsLeft += boxes[i] - '0';
    movesLeft += ballsLeft;

    int j = boxes.size() - 1 - i;
    result[j] += movesRight;
    ballsRight += boxes[j] - '0';
    movesRight += ballsRight;
  }

  return result;
}

int main()
{
  // 1769. Minimum Number of Operations to Move All Balls to Each Box

  {
    std::string boxes = "110";
    std::vector<int> expected = {1, 1, 3};
    auto result = minOperations(boxes);
    assert(minOperations(boxes) == expected);
  }

  {
    std::string boxes = "001011";
    std::vector<int> expected = {11, 8, 5, 4, 3, 4};
    auto result = minOperations(boxes);
    assert(minOperations(boxes) == expected);
  }

  return 0;
}
