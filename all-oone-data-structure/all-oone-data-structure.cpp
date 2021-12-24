class AllOne {
    
    unordered_map<string,int> freq;
    set<pair<int,string>> minimum;
    set<pair<int,string>, greater<pair<int,string>>> maximum;
    
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(freq.count(key)) {
            auto itr1 = minimum.find({freq[key], key});
            auto itr2 = maximum.find({freq[key], key});
            minimum.erase(itr1);
            maximum.erase(itr2);
        }
        freq[key]++;
        minimum.insert({freq[key], key});
        maximum.insert({freq[key], key});
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto itr1 = minimum.find({freq[key], key});
        auto itr2 = maximum.find({freq[key], key});
        minimum.erase(itr1);
        maximum.erase(itr2);
        freq[key]--;
        if(freq[key] == 0) freq.erase(key);
        else {
            minimum.insert({freq[key], key});
            maximum.insert({freq[key], key});
        }
        
        
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(maximum.size() == 0) return "";
        return maximum.begin()->second;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(minimum.size() == 0) return "";
        return minimum.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */