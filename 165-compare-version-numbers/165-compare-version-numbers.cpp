class Solution {

public:
    int compareVersion(string version1, string version2) {
        
        int i = 0;
        int n = version1.length(); 
        
        int j = 0;
        int m = version2.length();
        
        while(i < n or j < m) {
            
            int revision1 = 0;
            int revision2 = 0;
            
            
            while(i < n and version1[i] != '.')
                revision1 = (revision1 * 10) + (version1[i++] - '0');
                  
            
            while(j < m and version2[j] != '.')
                revision2 = (revision2 * 10) + (version2[j++] - '0');
            
            
            if(revision1 < revision2)
                  return -1;
                 
            if(revision1 > revision2)
                  return 1;
                  
            i++;
            j++;
            
        }
        
        return 0; 
    }
};