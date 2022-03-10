class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        auto head = new ListNode(INT_MIN);
        auto tail = head;
        int carry = 0;
        
        while(l1 or l2) {
            
            int sum = 0;
            
            if(l1) sum += l1 -> val;
            if(l2) sum += l2 -> val;
            
            sum += carry;
            
            tail -> next = new ListNode(sum % 10);
            tail = tail -> next;
            
            carry = sum / 10;
            
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
            
        }
        
        if(carry) {
            tail -> next = new ListNode(carry);
            tail = tail -> next;
        } 
        
        return head -> next;
        
    }
};
