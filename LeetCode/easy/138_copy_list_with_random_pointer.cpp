#include <unordered_map>
#include <iostream>

class Node 
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) 
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) 
{
    if (!head) {
        return nullptr;
    }

    std::unordered_map<Node*, Node*> copy;
    Node* end = head;
    while (end) {
        Node* node = new Node(end->val);
        copy.insert({end, node});
        end = end->next;
    }

    for (auto [original, cp]: copy) {
        cp->next = original->next ? copy[original->next] : cp->next = nullptr;
        cp->random = original->random ? copy[original->random] : nullptr;
    }

    return copy[head];    
}

Node* copyRandomList_v2(Node* head) 
{
    Node* curr = head;
    if (!curr) {
        return nullptr;
    }
    Node* prev = nullptr;
    Node* copyHead = nullptr;
    std::unordered_map<Node*, Node*> copy;
    while (curr) {
        Node* node = new Node(curr->val);
        copy.insert({curr, node});
        if (prev) {
            prev->next = node;
            prev = node;
        } else {
            copyHead = node;
            prev = node;
        }

        curr = curr->next;
    }

    curr = head;
    while (curr) {
        Node* copyCurr = copy[curr];
        Node* randomNode = copy[curr->random];
        copyCurr->random = randomNode;
        curr = curr->next;
    }
    
    return copyHead;    
}

int main()
{
    // 138. Copy List with Random Pointer
    return 0;
}
