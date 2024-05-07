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

ListNode* doubleIt(ListNode* head)
{
  ListNode* tmp = nullptr;
  ListNode* reversed = nullptr;

  ListNode* entry = head;
  while (entry) {
    tmp = entry;
    entry = entry->next;
    tmp->next = reversed;
    reversed = tmp;
  }

  ListNode* doubleHead = nullptr;

  int carryValue = 0;
  entry = reversed;
  while (entry) {
    tmp = entry;
    entry = entry->next;
    tmp->next = doubleHead;

    int value = 2 * tmp->val;
    tmp->val = value % 10 + carryValue;
    carryValue = value / 10;

    doubleHead = tmp;
  }

  if (carryValue > 0) {
    tmp = new ListNode(carryValue, doubleHead);
    doubleHead = tmp;
  }

  return doubleHead;
}

int main()
{
  // 2816. Double a Number Represented as a Linked List

  return 0;
}
