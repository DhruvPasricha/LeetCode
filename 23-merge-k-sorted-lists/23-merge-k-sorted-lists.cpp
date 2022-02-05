struct node{
    ListNode* add;  
    int val;
};

struct comp{
    
    bool operator()(const node &a,const node &b){
        return a.val > b.val;
    }
};


class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<node,vector<node>,comp> pq;
        
        
        for(int i = 0;i < lists.size();i++){
            if(lists[i] != NULL){
                node x;
                x.add = lists[i];
                x.val = lists[i]->val;
                pq.push(x);
            }
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(!pq.empty()){
            
            auto x = pq.top();
            pq.pop();
            
            ListNode* temp = new ListNode(x.val);
            
            if(head == NULL){
                head = temp;
                tail = temp;
            }else{
                tail -> next = temp;
                tail = temp;
            }
            
            if((x.add)->next != NULL){
                (x.add) = (x.add)->next;
                (x.val) = (x.add)->val;
                
                pq.push(x);
            }
        }
        
        return head;
    }
};