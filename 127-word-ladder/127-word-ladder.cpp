class Solution {

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st;
        
        for(string &word : wordList)
            st.insert(word);
    
        unordered_map<string, int> dist;
        queue<string> q;
        
        q.push(beginWord);
        dist[beginWord] = 1;
        
        while(q.size() > 0) {
            auto f = q.front();
            q.pop();
            
            if(f == endWord)
                return dist[f];
            
            int n = f.size();
            
            for(int i = 0; i < n;i++) {
                string f_ = f;
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    f_[i] = ch;
                    if(st.count(f_) and dist.count(f_) == 0) {
                        dist[f_] = dist[f] + 1;
                        q.push(f_);
                    }
                }
            } 
        }
        
        return 0;
    }
};