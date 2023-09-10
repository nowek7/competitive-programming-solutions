struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head)
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
  return reversed;
}

int main()
{
  return 0;
}