class MergeSort{
    
    static ListNode* merge(ListNode* head1, ListNode* head2) {
        
        
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
    
    
    static ListNode* getMid(ListNode* head) {
        
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
    
    static ListNode* sort(ListNode* head) {
        
        // [length <= 1 => already sorted]
        if(head == NULL or head -> next == NULL)
            return head;
        
        // [divide list into two parts]
        ListNode* mid = getMid(head);
    
        ListNode* first =  head; // [head......mid]
        ListNode* second = mid -> next; // [mid->next.....tail]
        
        mid -> next = NULL;
        
        // [sort both lists independently]
        first = sort(first);    
        second = sort(second);
        
        // [merge two sorted halves]
        head = merge(first, second);
        
        
        // [return the sorted list]
        return head;
    }
    
};


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
        
        ListNode* smallerHead = new ListNode(INT_MIN); // dummy node
        ListNode* smallerTail = smallerHead;
        
        ListNode* greaterHead = new ListNode(INT_MAX); // dummy node
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
            
            // [length <= 1 => already sorted]
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