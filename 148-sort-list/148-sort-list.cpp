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
class QuickSort{
    
    
    static ListNode* merge(ListNode* first, ListNode* pivot, ListNode* second) {
        
        
        ListNode* head = (first) ? first : pivot;
        
        while(first and first -> next)
            first = first -> next;
        
        if(first)
            first -> next = pivot;
        
        pivot -> next = second;
        
        return head;
    }
    
    static pair<ListNode*, ListNode*> partition(ListNode* head) {
        
        ListNode* smallerHead = new ListNode(INT_MIN);
        ListNode* smallerTail = smallerHead;
        
        ListNode* greaterHead = new ListNode(INT_MAX);
        ListNode* greaterTail = greaterHead;
        
        ListNode* ptr = head -> next;
        head -> next = NULL;
        
        while(ptr != NULL) {
            
            auto &tail = (ptr -> val <= head -> val) ? smallerTail : greaterTail;

            tail -> next = ptr;
            tail = tail -> next;
            ptr = ptr -> next;
            tail -> next = NULL;
        }
        
        return {smallerHead -> next, greaterHead -> next};
        
    }
    
    
    
    static bool is_sorted(ListNode* head) {
        
        ListNode* prev = new ListNode(INT_MIN);
        
        while(head ) {
            if(head -> val < prev -> val)
                return false;
            prev = head;
            head = head -> next;
        }
        
        return true;
    }
    
    
    public:
        
        static ListNode* sort(ListNode* head) {
            
            if(is_sorted(head))
                return head;

            // [split list into three parts]
            
            // [first -> ... -> NULL] + [head -> NULL] + [second -> ..... -> NULL]
            
            // first: contains all nodes <= head -> val
            // head: pivot node
            // second: contains all node > head -> val
        
            auto [first, second] = partition(head);
        
            // [sort both the lists independently]
            first = sort(first); 
            second = sort(second);
        
            // [merge first + head + second]
            head = merge(first, head, second);
            
            // [return the sorted list]
            return head;
            
        }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return QuickSort::sort(head);
    }
};