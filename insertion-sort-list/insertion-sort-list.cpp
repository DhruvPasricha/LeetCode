class Solution {
public:
    
    // inserts the 1st element from unsortedLL into the sortedLL such that sortedLL remains sorted
    ListNode* insert(ListNode* sortedHead, ListNode* unsortedHead){

        ListNode *current = sortedHead;
        ListNode* prev = NULL;
        
        while(current != 0 and current -> val < unsortedHead -> val){
            prev = current;
            current = current -> next;
        }
        
        if(prev == 0){
            unsortedHead -> next = sortedHead;
            sortedHead = unsortedHead;
        }else{
            prev -> next = unsortedHead;
            unsortedHead -> next = current;
        }
        return sortedHead;
    }
    
    ListNode* solveRec(ListNode* head) {
        
        // empty list
        if(head == 0) return 0; 
        
        // sorts the list from head->next till the end
        ListNode *smallSortedList = insertionSortList(head -> next); 
        
        // list is now sorted from head->next till the end
        
        // break the connection between the two
        head -> next = 0;
        
        // smallSortedList : a1 -> a2 -> a3 -> a4 ........
        // head : a0
        
        // insert head in the above smallSortedList
        head = insert(smallSortedList, head);
        
        // list is sorted
        return head;
    }
    
    
    ListNode* solveItr(ListNode* head) {
        
        // empty list
        if(head == 0) return 0;
        
        stack<ListNode*> st;
        
        // head : a0 -> a1 -> a2 ...... -> an-1
        
        // push first n - 1 nodes into the stack
        while(head -> next != 0){
            st.push(head);
            head = head -> next;
        }
        
        // head : an 
        // st (remaining) : an-1 , an-2 .............. , a0  
        
        // insert the remaining list nodes one by one in the head in sorted order 
        while(not st.empty()) {
            head = insert(head, st.top());
            st.pop();
        }
        
        return head;
        
    }
    
    ListNode* solveItr2(ListNode* head) {
        
        // empty list
        if(head == 0) return 0; 
        
        // head : a0 -> a1 -> a2 ......
        
        // breaking the connection between a0 and a1
        ListNode* remaining = head -> next;
        head -> next = 0;
        
        // head : a0
        // remaining : a1 -> a2 -> a3 ...........

        // insert the remaining list nodes one by one in the head in sorted order 
        while(remaining != 0){ 
            ListNode *next = remaining -> next;
            head = insert(head, remaining);
            remaining = next;
        }
        
        // list is sorted
        return head;
    }
    

    ListNode* insertionSortList(ListNode* head) {
        // head = solveRec(head);
        head = solveItr(head);
        // head = solveItr2(head);       
        return head;
    }
};