class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        multiset<int> st;
        
        int n = people.size();
        
        for(int i = 0; i < n; i++)
            st.insert(people[i]);
        
        sort(people.begin(), people.end());
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(st.count(people[i]) == 0) continue;
            
            ans++;
            
            auto itr = st.find(people[i]);
            st.erase(itr);
            
            itr = st.upper_bound(limit - people[i]);
             
            if(itr != st.begin()) {
                itr--;
                st.erase(itr);
            }
        }
        
        return ans;
    }
};