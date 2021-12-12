class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        for(int i = 0;i < n;i++) q.push(i);
        vector<int> Ans(n);
        int i = 0;
        while(q.size() != 0){
            auto f = q.front();
            Ans[f] = deck[i++];
            q.pop();
            
            if(q.size() > 0){
                f = q.front();
                q.pop();
                q.push(f);
            }
        }
        return Ans;
    }
}; 

    