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

ListNode* reverseBetween(ListNode* head, int left, int right)
{
  ListNode* clone = new ListNode(0);
  ListNode* next = clone;

  int i = 0;
  ListNode* entry = head;
  while (entry && ++i < left) {
    next->next = entry;
    entry = entry->next;
    next = next->next;
  }

  ListNode* tmp = nullptr;
  ListNode* reversed = nullptr;
  while (entry && left <= i && i <= right) {
    tmp = entry;
    entry = entry->next;
    tmp->next = reversed;
    reversed = tmp;
    ++i;
  }

  next->next = reversed;
  while (next->next) {
    next = next->next;
  }

  while (entry) {
    next->next = entry;
    entry = entry->next;
    next = next->next;
  }
  next = clone->next;
  delete clone;

  return next;
}

ListNode* reverseBetween_v2(ListNode* head, int left, int right)
{
  ListNode* clone = new ListNode(0);
  ListNode* next = clone;
  ListNode* tmp = nullptr;
  ListNode* reversed = nullptr;

  int i = 0;
  ListNode* entry = head;
  while (entry) {
    ++i;
    if (i < left || i > right) {
      next->next = entry;
      entry = entry->next;
      next = next->next;
    } else {
      tmp = entry;
      entry = entry->next;
      tmp->next = reversed;
      reversed = tmp;
    }
    if (i == right) {
      next->next = reversed;
      while (next->next) {
        next = next->next;
      }
    }
  }

  next = clone->next;
  delete clone;

  return next;
}

int main()
{
  return 0;
}