/*
    TC : O(N)
    SC : O(1)
    // we can find len of cycle in LinkedList
    //after that we can move ptr2 len steps ahead until ptr1!=ptr2
*/
#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val = 0;
    ListNode *next;

    ListNode(int val) {
        this->val = val;
        next = nullptr;
    }
};

ListNode* findStart(ListNode* head, int len) {
    ListNode*ptr1 = head, *ptr2 = head;
    while (len > 0) {
        ptr2 = ptr2->next;
        len -= 1;
    }

    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}

int calculateLen(ListNode* slow) {
    ListNode* current = slow;
    int len = 0;
    do {
        current = current->next;
        len += 1;
    } while (current != slow);

    return len;
}

ListNode* hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    int len = 0;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) {
            len = calculateLen(slow);
            break;
        }
    }

    return findStart(head, len);
}

int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    head->next->next->next->next->next->next = head->next->next;
    //1->2->3->4->2
    cout << hasCycle(head)->val << " :: LinkedListCycleStart" << endl;
}