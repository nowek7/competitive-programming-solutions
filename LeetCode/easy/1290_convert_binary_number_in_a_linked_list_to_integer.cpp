#include <cmath>
#include <vector>

struct ListNode
{
  int val;
  ListNode* next;

  ListNode():
    val(0),
    next(nullptr)
  {
  }

  ListNode(int x):
    val(x),
    next(nullptr)
  {
  }

  ListNode(int x, ListNode* next):
    val(x),
    next(next)
  {
  }
};

int getDecimalValue(ListNode* head)
{
  std::vector<int> values;
  ListNode* entry = head;
  while (entry) {
    values.push_back(entry->val);
    entry = entry->next;
  }

  int result = 0;
  for (int i = values.size() - 1, j = 0; i >= 0; --i, ++j) {
    if (values[i] == 1) {
      result += std::pow(2, j);
    }
  }

  return result;
}

int main()
{
  // 1290. Convert Binary Number in a Linked List to Integer

  return 0;
}