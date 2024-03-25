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

bool isPalindrome(ListNode* head)
{
  std::vector<int> nums;
  ListNode* entry = head;
  while (entry) {
    nums.push_back(entry->val);
    entry = entry->next;
  }

  for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
    if (nums[i] != nums[j]) {
      return false;
    }
  }

  return true;
}

bool isPalindrome_v2(ListNode* head)
{
  if (!head || !head->next) {
    return true;
  }

  ListNode* slow = head;
  ListNode* fast = head;
  ListNode* prev = NULL;

  while (fast && fast->next) {
    fast = fast->next->next;
    ListNode* temp = slow->next;
    slow->next = prev;
    prev = slow;
    slow = temp;
  }

  if (fast) {
    slow = slow->next;
  }

  while (prev && slow) {
    if (prev->val != slow->val) {
      return false;
    }
    prev = prev->next;
    slow = slow->next;
  }

  return true;
}

int main()
{
  // 234. Palindrome Linked List

  return 0;
}
