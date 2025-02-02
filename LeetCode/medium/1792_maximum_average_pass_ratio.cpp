#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents)
{
  auto getGainByAddingStudent = [](auto pass, auto total) {
    return ((pass + 1) / static_cast<double>(total + 1)) - (pass / static_cast<double>(total));
  };

  std::priority_queue<std::pair<double, std::pair<int, int>>> pq;
  for (const auto& classEntry: classes) {
    const auto gain = getGainByAddingStudent(classEntry[0], classEntry[1]);
    pq.push(std::make_pair(gain, std::make_pair(classEntry[0], classEntry[1])));
  }

  while (extraStudents > 0) {
    auto [gain, classEntry] = pq.top();
    pq.pop();

    const auto newGain = getGainByAddingStudent(classEntry.first + 1, classEntry.second + 1);
    pq.push(std::make_pair(newGain, std::make_pair(classEntry.first + 1, classEntry.second + 1)));

    --extraStudents;
  }

  auto sum = 0.0;
  while (!pq.empty()) {
    const auto& [_, classEntry] = pq.top();
    const auto [pass, total] = classEntry;
    sum += (pass / static_cast<double>(total));

    pq.pop();
  }

  return sum / static_cast<double>(classes.size());
}

int main()
{
  // 1792. Maximum Average Pass Ratio

  constexpr auto EPSILON = 1e8;

  {
    std::vector<std::vector<int>> students = {
      {1, 2},
      {3, 5},
      {2, 2}
    };
    int extraStudents = 2;
    auto expectedRatio = 0.78333;
    assert(maxAverageRatio(students, extraStudents) - expectedRatio < EPSILON);
  }

  {
    std::vector<std::vector<int>> students = {
      {2,  4},
      {3,  9},
      {4,  5},
      {2, 10}
    };
    int extraStudents = 4;
    auto expectedRatio = 0.53485;
    assert(maxAverageRatio(students, extraStudents) - expectedRatio < EPSILON);
  }

  return 0;
}
