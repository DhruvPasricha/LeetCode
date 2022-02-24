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

class Sorting{
    
    
    
    ListNode* merge(ListNode* head1, ListNode* head2) {
        
        
        ListNode *head = new ListNode(0); // dummy head node
        ListNode *tail = head;
        
        
        while(head1 and head2) {
            
            auto &current = (head1 -> val <= head2 -> val) ? head1 : head2;
            
            tail -> next = current;
            tail = tail -> next;
            current = current -> next;
        }
        
        
        if(head1)
            tail -> next = head1;
        else if(head2)
            tail -> next = head2;
        
        
        return head -> next;
    }
    
    
    ListNode* getMid(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* slow = head, *fast = head;
        
        while(fast and fast->next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return prev;
        
    } 
    
    
  public:
    
    ListNode* mergeSort(ListNode* head) {
        
        // [length <= 1 => already sorted]
        if(head == NULL or head -> next == NULL)
            return head;
        
        // [divide list into two parts]
        ListNode* mid = getMid(head);
    
        ListNode* first =  head; // [head......mid]
        ListNode* second = mid -> next; // [mid->next.....tail]
        
        mid -> next = NULL;
        
        // [sort both lists independently]
        first = mergeSort(first);    
        second = mergeSort(second);
        
        // [merge two sorted halves]
        head = merge(first, second);
        
        
        // [return the sorted list]
        return head;
    }
    
};





class Solution {
public:
    ListNode* sortList(ListNode* head) {
        Sorting obj;
        return obj.mergeSort(head);
    }
};