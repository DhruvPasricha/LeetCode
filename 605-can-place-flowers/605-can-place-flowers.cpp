class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int f) {
        int i = 0;
        int n = flowerbed.size();
        
        int mx = 0;
        
        while(i < n) {
            
            int count = (i == 0 and flowerbed[i] == 0);
            
            if(flowerbed[i] == 1) i++;
            
            while(i < n and flowerbed[i] == 0) {
                count++;
                i++;
            }
            
            if(i < n) count--;
            
            mx += (count >> 1);
            
        }
        
        return mx >= f;
    }
};