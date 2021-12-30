class Solution {
public:
    int smallestRepunitDivByK(int k) {
        for(int i = 0, l = 1, x = 1;i < k + 1;i++, x = x*10 + 1) {
            x %= k;
            if(x == 0) return i + 1;
        }
        return -1;
    }
};