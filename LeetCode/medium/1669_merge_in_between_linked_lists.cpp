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

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
{
  ListNode* result = new ListNode(0);
  ListNode* entry = result;

  int counter = 0;
  ListNode* entry1 = list1;
  while (entry1 && counter <= b) {
    if (counter < a) {
      entry->next = new ListNode(entry1->val);
      entry = entry->next;
    }

    entry1 = entry1->next;
    ++counter;
  }

  ListNode* entry2 = list2;
  while (entry2) {
    entry->next = new ListNode(entry2->val);
    entry = entry->next;
    entry2 = entry2->next;
  }

  while (entry1) {
    entry->next = new ListNode(entry1->val);
    entry = entry->next;
    entry1 = entry1->next;
  }

  ListNode* tmp = result;
  entry = result->next;
  delete tmp;

  return entry;
}

int main()
{
  // 1669. Merge In Between Linked Lists

  return 0;
}
