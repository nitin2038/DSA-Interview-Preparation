/*
    TC : O(N)
    SC : O(1)
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

int calculateLen(ListNode* slow) {
    ListNode* current = slow;
    int len = 0;
    do {
        current = current->next;
        len+=1;
    } while(current!=slow);
    
    return len;
}

int hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast!=nullptr && fast->next!=nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        
        if(slow == fast)
           return calculateLen(slow);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next = head->next;  
    //1->2->3->4->2
    cout<<hasCycle(head)<<" :: cycleLen"<<endl;
}