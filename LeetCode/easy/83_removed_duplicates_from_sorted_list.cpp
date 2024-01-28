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

ListNode* deleteDuplicates(ListNode* head)
{
  if (!head) {
    return head;
  }
  ListNode* result = head;
  ListNode* curr = head;
  ListNode* next = nullptr;
  while (curr) {
    next = curr->next;
    while (next && next->val == curr->val) {
      ListNode* tmp = next;
      next = next->next;
      delete tmp;
    }
    curr->next = next;
    curr = curr->next;
  }

  return result;
}

ListNode* deleteDuplicates_v2(ListNode* head)
{
  if (!head) {
    return head;
  }

  ListNode* curr = head;
  while (curr && curr->next) {
    if (curr->next->val == curr->val) {
      curr->next = curr->next->next;
    } else {
      curr = curr->next;
    }
  }

  return head;
}

int main()
{
  // 83. Remove Duplicates from Sorted List

  return 0;
}
