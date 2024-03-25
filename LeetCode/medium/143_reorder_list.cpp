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

void reorderList(ListNode* head)
{
  if (!head && !head->next) {
    return;
  }

  ListNode* middle = head;
  ListNode* end = head;
  while (end && end->next) {
    middle = middle->next;
    end = end->next->next;
  }

  ListNode* prev = nullptr;
  ListNode* next = nullptr;
  while (middle) {
    next = middle->next;
    middle->next = prev;
    prev = middle;
    middle = next;
  }

  ListNode* firstHalf = head;
  ListNode* secondHalf = prev;
  while (secondHalf->next) {
    next = firstHalf->next;
    prev = secondHalf->next;

    firstHalf->next = secondHalf;
    secondHalf->next = next;

    firstHalf = next;
    secondHalf = prev;
  }
}

int main()
{
  // 143. Reorder List

  return 0;
}