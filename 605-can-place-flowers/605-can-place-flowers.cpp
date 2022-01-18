class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int f) {
        int i = 0;
        int n = flowerbed.size();
        
        int mx = 0;
        int count = 0;
        
        while(i < n and flowerbed[i] == 0) {
            count++;
            i++;
        }
        
        if(i == n) mx += ((count + 1) >> 1);
        else mx += (count >> 1);
        
        while(i < n) {
            
            count = 0;
            i++;
            
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
