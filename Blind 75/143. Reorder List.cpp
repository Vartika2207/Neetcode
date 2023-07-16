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
    /*************USING REVERSE LIST***********/
    ListNode* reverse(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        ListNode *headNext = head->next;
        ListNode *headNew = reverse(headNext);
        (head->next)->next = head; head->next = NULL;
        return headNew;
    }
    
    void reorderListNaive(ListNode* head) {
        if(!head or !head->next)
            return;
        
        // finding mid of list
        ListNode *slow = head, *fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *head1 = head, *head2 = slow->next;
        slow->next = NULL;
        head2 = reverse(head2);
        
        // merging two linked list
        while(head1 and head2) {
            ListNode *head1_next = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = head2->next;
            head1->next = head1_next;
            head1 = head1->next;
        }  
    }
    /************************/
    
    /**********USING STACK**************/
    void reorderListStack(ListNode* head) {
        if(!head or !head->next)
            return;
        
        // finding mid of list
        ListNode *slow = head, *fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *head1 = head, *head2 = slow->next;
        slow->next = NULL;
        
        // stack to reverse the list after mid (i.e. slow)
        stack<ListNode*> st;
        while(head2) {
            st.push(head2);
            head2 = head2->next;
        }
        
        // merging two linked list
        while(head1 and st.size()) {
            ListNode *head1_next = head1->next;
            head1->next = st.top();
            st.pop();
            head1 = head1->next;
            head1->next = head1_next;
            head1 = head1->next;
        }  
        
    }
  /***************Using Recursion-incomplete****************/  
    ListNode *mergeList(ListNode *head1, ListNode *head2) {
        if(!head1 or head2)
            return !head1?head2:head1;
        
        ListNode *head1_temp = head1->next, *head = head1;
        head1->next = head2;
        head1 = head1->next;
        head1->next = mergeList(head1_temp, head2->next);
        return head;
    }
    
    void reorderListRec(ListNode* head) {
        if(!head or !head->next)
            return;
        
        // finding mid of list
        ListNode *slow = head, *fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *head1 = head, *head2 = slow->next;
        slow->next = NULL;
        
        head = mergeList(head1, head2);
    }
    
public:
    void reorderList(ListNode* head) {
        reorderListRec(head);
    }
};
