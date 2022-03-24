class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        map<int, int> mp;
        
        int n = people.size();
        
        for(int i = 0; i < n; i++)
            mp[people[i]]++;
        
        sort(people.begin(), people.end());
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(mp.count(people[i]) == 0) continue;
            
            ans++;
            
            mp[people[i]]--;
            
            if(mp[people[i]] == 0) mp.erase(people[i]);
            
            auto itr = mp.upper_bound(limit - people[i]);
             
            if(itr != mp.begin()) {
                
                itr--;
                itr->second--;
                
                if(itr -> second == 0)
                    mp.erase(itr);
            }
        }
        
        return ans;
    }
};