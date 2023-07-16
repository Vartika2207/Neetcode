/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // time: O(n), space: O(n)
    bool hasCycle_map(ListNode *head) {
       if(!head)
           return true;
        
        unordered_set<ListNode*> mp;
        ListNode *temp = head;
        while(temp) {
            if(mp.find(temp) != mp.end())
                return true;
            mp.insert(temp);
            temp = temp->next;
        }
        return false;
    }
    
    // time: O(n), space: O(1)
    bool hasCycle_tortoise(ListNode *head) {
       if(!head)
           return head;
        
        ListNode *fast = head, *slow = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
    
public:
    bool hasCycle(ListNode *head) {
       return  hasCycle_tortoise(head);
    }
};
