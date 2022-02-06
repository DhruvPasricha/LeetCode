class Bitset {
    
    string s;
    string t;
    int setCount_a = 0;
    int setCount_b = 0;
public:
    Bitset(int size) {
        while(s.length() < size) s += '0';
        while(t.length() < size) t += '1';
        setCount_b = size;
    }
    
    void fix(int idx) {
        
        if(s[idx] == '1') 
            return;
        
        s[idx] = '1';
        t[idx] = '0';
        setCount_a++;
        setCount_b--;
    }
    
    void unfix(int idx) {

        if(s[idx] == '0') 
            return;
        
        s[idx] = '0';
        t[idx] = '1';
    
        setCount_a--;
        setCount_b++;
    }
    
    void flip() {
        s.swap(t); // O(1)
        swap(setCount_a, setCount_b);
    }
    
    bool all() {
        return setCount_a == s.size();
    }
    
    bool one() {
        return setCount_a > 0;  
    }
    
    int count() {
        return setCount_a;  
    }
    
    string toString() {
        return s;
    }
};
