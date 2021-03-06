class Solution {
    
    // Solution 1 (More generic) 
    
    // sum of subarray should be = len / 2    
    // pre[r] - pre[l - 1] = (r - (l - 1)) / 2
    // 2 * pre[r] - 2 * pre[l - 1] = r - l + 1
    // (2 * pre[r] - r) = (2 * pre[l - 1] - (l - 1))
    
    // if(l > 0) 
        // (2 * pre[r] - r) = (2 * pre[l - 1] - (l - 1))

    // if(l == 0) 
        // pre[l - 1] = 0
        // 2 * pre[r] - r = 1
        // => minIndex[1] = - 1

    // for each r find the minimum l - 1
        // len => max(len, r - (l - 1))

    int solution1(vector<int> &nums) {
     
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
    
    // Solution 2 : 
    
    // replace all 0's with -1
    
    // Now we are looking for the longest subarray having sum = 0
    
    // pre[r] - pre[l - 1] = 0
    
    // if(l > 0)
        // pre[r] = pre[l - 1]
    
    // if(l == 0)
        // pre[r] = 0
        // => minIndex[0] = -1
    
    int solution2(vector<int> &nums) {
        
        unordered_map<int, int> minIndex;
        
        int n = nums.size();
        int prefixSum = 0;
        int ans = 0;
        
        minIndex[0] = -1;
        
        for(int i = 0;i < n;i++) {
            
            prefixSum += (nums[i] == 0) ? -1 : 1;
            
            int req = prefixSum;
            
            if(minIndex.count(req))
                ans = max(ans, i - minIndex[req]);
            else
                minIndex[req] = i;
            
        }
        
        return ans;
    }
    
public:
    int findMaxLength(vector<int>& nums) {
        // return solution1(nums);
        return solution2(nums);
    }
};
 

