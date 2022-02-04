class Solution {

// sum of subarray should be = len / 2    

// pre[r] - pre[l - 1] = (r - (l - 1)) / 2

// 2 * pre[r] - 2 * pre[l - 1] = r - l + 1
// 2 * pre[r] - r = 2 * pre[l - 1] - (l - 1)

// if(l > 0) 
    // 2 * pre[r] - r = 2 * pre[l - 1] - (l - 1)

// if(l == 0) 
    // pre[l - 1] = 0
    // 2 * pre[r] - r = 1
    // => minIndex[1] = -1

// for each r find the minimum l - 1
    
    
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> minIndex;
        
        int n = nums.size();
        int prefixSum = 0;
        int ans = 0;
        minIndex[1] = -1;
        
        for(int i = 0;i < n;i++) {
            
            prefixSum += nums[i];
            
            int req = 2 * prefixSum - i;
            
            if(minIndex.count(req))
                ans = max(ans, i - minIndex[req]);
            else
                minIndex[req] = i;
            
        }
        
        return ans;
    }
};
 

