class Solution {

    int getMSB(int64_t n) {
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n = n + 1;
        n >>= 1;
        return n;
    }
    public:
    int findComplement(int num) {
        int MSB = getMSB(num);
        MSB += (MSB - 1);
        return MSB ^ num; 
    }
};