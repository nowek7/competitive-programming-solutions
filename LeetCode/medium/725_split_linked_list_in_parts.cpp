#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::vector<ListNode*> splitListToParts(ListNode* head, int k)
{
    std::vector<ListNode*> parts(k, nullptr);
    if (!head) {
        return parts;
    }

    int size = 0;
    for (ListNode* entry = head; entry != nullptr; entry = entry->next) {
        ++size;
    }

    ListNode* prev = nullptr;
    ListNode* entry = head;
    for (int i = 0, extra = size % k; entry && i < k; ++i, --extra) {
        parts[i] = entry;

        for (int j = 0; j < (size / k) + (extra > 0); ++j) {
            prev = entry;
            entry = entry->next;
        }
        prev->next = nullptr;
    }

    return parts;
}

int main()
{
    // 725. Split Linked List in Parts
    return 0;
}