class Solution {
    
    int mod = 1e4 + 1;
    
    int init(vector<int> &gas, vector<int> &cost) {
          
        int n = gas.size();
        
        // cost[i] = [gas[i] * (mod)]  + cost[i]; 
        for(int i = 0;i < n;i++) 
            cost[i] += (mod * gas[i]);
        
        // converting gas[i] to prefix Array
        gas[0] = gas[0] - cost[0] % mod;
        for(int i = 1;i < n;i++)
            gas[i] = gas[i - 1] + (gas[i] - (cost[i] % mod));
        
        int total = gas[n - 1]; 
        
        // converting gas[i] to suffixMin Array 
        for(int i  = n - 2;i >= 0;i--) 
            gas[i] = min(gas[i], gas[i + 1]);
        
        return total;
    }
    
    
    void recover(vector<int> &gas, vector<int> &cost) {
        
        int n = gas.size();
        
        for(int i = 0;i < n;i++) {
            gas[i] = cost[i] / mod;
            cost[i] %= mod;
        }
    }
    
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        int total = init(gas, cost);
        vector<int> &suffixMin = gas;
        
        int prefix = 0;
        int prefixMin = INT_MAX; 
        int ans = -1;
        
        for(int i = 0; i < n; i++) {
            
            int rightExtra = (i == 0) ? 0 : prefix;  
            int leftRemaining = total - rightExtra;
            
            int leftMin = (i == 0) ? 0 : prefixMin + leftRemaining;
            int rightMin = suffixMin[i] - rightExtra; 
            
            int pathMin = min(leftMin, rightMin);
            
            if(pathMin >= 0) {
                ans = i;
                break;
            }
            
            prefix += ((cost[i] / mod) - (cost[i] % mod));
            prefixMin = min(prefixMin, prefix);
            
        }
        
        recover(gas, cost);
        
        return ans;
    }
};
