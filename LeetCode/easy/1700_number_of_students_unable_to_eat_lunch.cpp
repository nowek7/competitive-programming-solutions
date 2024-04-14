#include <algorithm>
#include <cassert>
#include <vector>

int countStudents(std::vector<int>& students, std::vector<int>& sandwiches)
{
  int circularStudents = std::count(students.cbegin(), students.cend(), 0);
  int squareSandwiches = students.size() - circularStudents;

  for (auto sandwich: sandwiches) {
    if (sandwich == 0) {
      if (circularStudents > 0) {
        --circularStudents;
      } else {
        break;
      }
    } else {
      if (squareSandwiches > 0) {
        --squareSandwiches;
      } else {
        break;
      }
    }
  }

  return circularStudents + squareSandwiches;
}

int main()
{
  // 1700. Number of Students Unable to Eat Lunch

  {
    std::vector<int> students = {1, 1, 0, 0};
    std::vector<int> sandwiches = {0, 1, 0, 1};
    assert(countStudents(students, sandwiches) == 0);
  }

  {
    std::vector<int> students = {1, 1, 1, 0, 0, 1};
    std::vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    assert(countStudents(students, sandwiches) == 3);
  }

  return 0;
}
