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

class Solution
{
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
  {
    ListNode* sortedList = new ListNode(0);
    ListNode* elem = sortedList;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        elem->next = new ListNode(list1->val);
        list1 = list1->next;
      } else {
        elem->next = new ListNode(list2->val);
        list2 = list2->next;
      }

      elem = elem->next;
    }

    while (list1) {
      elem->next = new ListNode(list1->val);
      elem = elem->next;
      list1 = list1->next;
    }

    while (list2) {
      elem->next = new ListNode(list2->val);
      elem = elem->next;
      list2 = list2->next;
    }

    elem = sortedList;
    sortedList = sortedList->next;
    delete elem;

    return sortedList;
  }
};
