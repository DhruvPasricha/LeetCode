class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int i = 0;
        int j = people.size() - 1;
        
        int ans = 0;
        
        while(i <= j) {
            
            ans++;
            
            if(people[i] <= limit - people[j])
                i++;
            
            j--;
        }
        
        return ans;
    }
};