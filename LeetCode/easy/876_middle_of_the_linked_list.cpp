/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* end = head;
        ListNode* middle = head;
        while (end != nullptr && end->next != nullptr) {
            end = end->next->next;
            middle = middle->next;
        }
        return middle;
    }
};