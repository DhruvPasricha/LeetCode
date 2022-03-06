class DSU{
public:
    
    vector<int> parent;
    vector<int> size;
    
    
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        
        for(int i = 0;i < n;i++)
            parent[i] = i, size[i] = 1;
    }
    
    int get(int x) {
        
        if(parent[x] == x)
            return x;
        
        return parent[x] = get(parent[x]);
    }
    
    
    void join(int a, int b) {
        
        a = get(a);
        b = get(b);
        
        if(a == b) return;
        
        if(size[a] < size[b]) swap(a, b);
        
        parent[b] = a;
        size[a] += size[b];
    }
    
};


class Solution {
    
    
    vector<int> getSpf(int n) {
    
        vector<int> spf(n + 1);
        
        for(int i = 1;i <= n;i++)
            spf[i] = i;
        
        for(int i = 2;i * i <= n;i++)
            if(spf[i] == i)
                for(int j = i * i; j <= n; j += i)
                    spf[j] = min(spf[j], i);
        
        return spf;
        
    }
    
    
    
    
public:
    bool gcdSort(vector<int>& nums) {
        
        set<int> st;
        
        for(int &num : nums)
            st.insert(num);
        
        DSU dsu(1e5 + 1);
        
        auto spf = getSpf(1e5);
        
        map<int,int> mp;
        
        
        for(int num : st) {
            
            int temp = num;
            
            while(num != 1) {
                
                if(mp.count(spf[num])) {
                    dsu.join(mp[spf[num]], temp);
                } else {
                    mp[spf[num]] = temp;
                }
                
                num /= spf[num];
                
            }
        }
        
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        
        int n = nums.size();
        
        for(int i = 0;i < n;i++)
            if(dsu.get(nums[i]) != dsu.get(temp[i]))
                return false;
        
        return true;
        
    }
};