/* 
    TC : O(log n)
    SC : O(1)
    // we have to return the linkedList back to its original form as well (as part of qn)
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

ListNode *reverseLL(ListNode* head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
        ListNode* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }

    return prev;
}

bool isPalindrome(ListNode* head, ListNode* slow, ListNode* currentMiddlePtr) {
    //base case
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode* copyMiddle = slow;
    while (slow != nullptr) {
        if (head->val != slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    currentMiddlePtr->next = reverseLL(copyMiddle);
    return true;
}

bool middleLL(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverseLL(slow->next);
    ListNode* currentMiddlePtr = slow;
    slow = slow->next;
    return isPalindrome(head, slow, currentMiddlePtr);
}

void solve() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    cout << middleLL(head) << " :isPalindrome";
}

int main() {
    solve();
}