// Macros
#define v vector
// Trie
class TrieNode {
    
    friend class Trie;
    
    TrieNode* children[2];
    
    bool hasChild(int ch) {
        return children[ch] != 0;
    }
    
    TrieNode *getChild(int ch) {
        
        if(children[ch] == NULL)
            children[ch] = new TrieNode();
        
        return children[ch];
    }
    
    TrieNode() {
        children[0] = children[1] = 0;
    }
    
    // ~TrieNode() {
    //     for(int i = 0;i < 2;i++) {
    //         if(children[i] != 0) {
    //             delete children[i];
    //         }
    //     }
    // }
};


class Trie {
    
    TrieNode* root = NULL;
    
public:
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        
        auto r = root;
        
        for(int i = 30;i >= 0;i--) {
            int cur = (num & (1 << i)) != 0;
            r = r -> getChild(cur);
        }
    }
    
    int query(int num) {
        
        auto r = root;
        int ans = 0;
        
        for(int i = 30;i >= 0;i--) {
            
            int cur = (num & (1 << i)) != 0;
            int req = cur ^ 1;
            
            if(r->hasChild(req)) {
                ans += (1 << i);
                r = r -> getChild(req);    
            } else {
                r = r -> getChild(cur);
            }
            
        }
        
        return ans;
    }
    
    // ~Trie() {
    //     delete root;
    // }
};

// Solution
class Solution {
    
    v<int> queries;
        
    void init(v<v<int>> &q)  {
        
        int n = q.size();
        queries.resize(n);
        
        for(int i  = 0;i < n;i++) {
            queries[i] = i;
        }
        
        sort(queries.begin(), queries.end(), [&](int a, int b){
            if(q[a][1] != q[b][1])
                return q[a][1] < q[b][1];
            return a < b;
        });
        
    }
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        cin.tie(nullptr)->sync_with_stdio(false);
       
        init(q);
        Trie t;        
        
        sort(nums.begin(), nums.end());
        
        int i = 0; int n = nums.size(); // nums
        int j = 0; int m = queries.size(); // query
        
        v<int> Ans(m);

        while(j < m) {
            
            while(i < n and nums[i] <= q[queries[j]][1]) {
                t.insert(nums[i]);
                i++;
            }
            
            Ans[queries[j]] = (i == 0) ? -1 :  t.query(q[queries[j]][0]);
            j++;
        }
        
        return Ans;
        
    }
};