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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
  int length = 0;
  ListNode* entry = head;
  while (entry) {
    ++length;
    entry = entry->next;
  }

  if (length == n) {
    ListNode* tmp = head;
    head = head->next;
    delete tmp;
    return head;
  }

  int idx = 0;
  entry = head;
  while (idx != length - n - 1) {
    ++idx;
    entry = entry->next;
  }

  ListNode* tmp = entry->next;
  entry->next = entry->next->next;
  delete tmp;

  return head;
}

int main()
{
  // 19. Remove Nth Node From End of List

  return 0;
}
