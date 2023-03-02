/*
    TC : O(n)
    SC : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    ListNode *next;
    int val = 0;

    ListNode(int val) {
        this->val = val;
        next = nullptr;
    }
};

ListNode *middleLL(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}



void solve() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << middleLL(head)->val << " ::middle of LinkedList";
}

int main() {
    solve();
}