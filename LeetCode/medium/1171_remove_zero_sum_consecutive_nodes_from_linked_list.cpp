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

ListNode* removeZeroSumSublists(ListNode* head)
{
  std::vector<int> nums;
  ListNode* entry = head;
  while (entry) {
    nums.push_back(entry->val);
    entry = entry->next;
  }

  for (int i = 0; i < nums.size(); ++i) {
    int sum = 0;
    for (int end = i; end < nums.size(); ++end) {
      sum += nums[end];
      if (sum == 0) {
        for (int j = i; j <= end; ++j) {
          nums[j] = 0;
        }
        break;
      }
    }
  }

  ListNode* root = new ListNode(0);
  entry = root;
  for (auto item: nums) {
    if (item != 0) {
      entry->next = new ListNode(item);
      entry = entry->next;
    }
  }
  entry = root->next;
  delete root;

  return entry;
}

int main()
{
  // 1171. Remove Zero Sum Consecutive Nodes from Linked List

  return 0;
}