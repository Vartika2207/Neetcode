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
    
    
    
//     ListNode *sortLL(ListNode *head) {
//         if(!head or !head->next)
//             return head;
        
//         // finding mid of list
//         ListNode *slow = head, *fast = head;
//         while(fast and fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
        
//         ListNode *l1 = head, *l2 = slow->next;
//         slow->next = NULL;
        
//         if(l1->val < l2->val) {
//             l1-
//         }
        
//         return mergeLL(l1, l2);
//     }
    
//     ListNode* mergeKLists_naive(vector<ListNode*>& lists) {
//         if(!lists.size())
//             return NULL;
        
//         LisrNode *head = NULL;
        
//         //merging all lists in one list
//         for(int i=0; i<lists.size(); i++) {
//             ListNode *list = lists[i];
//             while(list) {
//                 if(!head) {
//                     head = list; list = list->next;
//                 }
//                 else {
//                     head->next = list;
//                     list = list->next;
//                     head = head->next;
//                 }
//             }
//         }
//         return sortLL(head);
//     }
    
    ListNode* mergeKLists_naive(vector<ListNode*>& lists) {
        // put all element in vector of <int, ListNode> type
        // sort vector based on int value and prepare a linkedlist from that sorted vector
//https://leetcode.com/problems/merge-k-sorted-lists/discuss/1746240/C++-Solution-w-Explanation-or-Step-by-step-optimisation-or-Three-different-approaches
        return NULL;
    }
    
    /*********APPROACH-2, HEAP***************/
    #define pi pair<int, ListNode* >
    //Time:O(n log k)-> as we are using min heap ;Space:O(k)-> at a single point of time min heap always handle the k elements
    ListNode* mergeKLists_heap(vector<ListNode*>& lists) {
        int k = lists.size(); // taking the size of the linked list
        
        if(k == 0) // if no linked list is present
            return NULL; // simply return null
        
        priority_queue<pi, vector<pi>, greater<pi>> minh; // making min-priority queue
        
        for(int i = 0; i < k; i++) // traverse from the whole array 
        {
            ListNode* curr_list = lists[i]; // extracting current linked list
            
            if(curr_list != NULL) // if element present in the linked list
            {
                minh.push({curr_list -> val, curr_list}); // push into min heap
                
            }
        }
        
        // this does not gurantee that k is zero, 
        // suppose an array like this [[],[],[],],here k = 3 and size of array is 0
        if(minh.size() == 0) // if their is no element i.e zero element
            return NULL;
        
        ListNode* head = new ListNode(); // can also be called as dummy
        ListNode* curr = head; // make a pointer pointing to head
        
        while(minh.empty() == false) // adding further most elements to min heap
        {
            pair<int, ListNode*> temp = minh.top(); // extracting top pair
            minh.pop(); // pop that pair
            
            if(temp.second -> next != NULL) // if elements still remaining in the linked list then push them
            {
                minh.push({temp.second -> next -> val, temp.second -> next});
            }
            
            curr -> next = temp.second;
            curr = curr -> next;
        }
        
        curr -> next = NULL; 
        head = head -> next; // move head, which is actually containg the list
        
        return head; // return head
    }
    /***********************/
    
    
    /********APPROACH-3, two pointer**********/
    //time: O(nlogk); space: O(1)
    ListNode* mergeTwoListsRec(ListNode* list1, ListNode* list2) {
        if(!list1 or !list2)
            return !list1?list2:list1;
        
        ListNode *head = nullptr;
        if(list1->val < list2->val) {
            head = list1; 
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }
        
        head->next = mergeTwoListsRec(list1, list2);
        return head;
    }
    ListNode* mergeTwoLis_twoPointer(vector<ListNode*>& arr) {
        int k = arr.size(); // extracting size of array
        if(k == 0) // if size of array is value
            return NULL;
        
        int start = 0; // start pointer
        int last = k -1; // last pointer
        int temp;
        while(last != 0) // if last pointer not becomes zero
        {
            start = 0;
            temp = last;
            while(start < temp)
            {
                // merge them and store in one of the linked list
                arr[start] = mergeTwoListsRec(arr[start],arr[temp]);
                start++; // increment start
                temp--; // decrese start
                
                if(start >= temp) // if at any point start passes the temp
                {
                    last = temp;
                }
            }
        }
        return arr[0]; // return first linked list of the aray as now it contains the all nodes in the sorted order.
        
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeTwoLis_twoPointer(lists);
    }
};
