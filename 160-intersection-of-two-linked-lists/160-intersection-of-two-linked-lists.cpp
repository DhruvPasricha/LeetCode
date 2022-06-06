class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        set<ListNode*> st;
        
        while(headA != NULL and headB != NULL)  {
            
            if(st.count(headA))
                return headA;
            
            st.insert(headA);
            
            headA = headA -> next;
            
            if(st.count(headB))
                return headB;
            
            st.insert(headB);
            
            headB = headB -> next;
            
        }
        
        
        while(headA) {
            
            if(st.count(headA))
                return headA;
            
            st.insert(headA);
            
            headA = headA -> next;
        }
        
         while(headB)  {
            
            if(st.count(headB))
                return headB;
            
            st.insert(headB);
            
            headB = headB -> next;
        }
        
       
        return NULL;
    }
};