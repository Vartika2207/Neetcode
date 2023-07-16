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
    /*************Better TWO POINTER**********/
    //time O(n); space O(1)
    ListNode* helper_tortoise(ListNode* head, int n){
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* slow=dummy, *fast=dummy;
        int temp=n;
        while(temp--){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode* nodeToRemove=slow->next;
        slow->next=nodeToRemove->next;
        
        delete nodeToRemove; // Free memory
        return dummy->next;
        
    }
    
    
    /***********************/
    ListNode* removeNthFromEnd_naive(ListNode* head, int n) {
        ListNode* iter = head;
        int len = 0, i = 1;
        while(iter) iter = iter -> next, len++;    // finding the length of linked list
        if(len == n) return head -> next;          // if head itself is to be deleted, just return head -> next
        for(iter = head; i < len - n; i++) iter = iter -> next; // iterate first len-n nodes
        iter -> next = iter -> next -> next;      // remove the nth node from the end
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNthFromEnd_naive(head, n);
    }
};
