class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return String
     */
    function getXor(&$s) {
        
        $ans = 0;
       
        $n = strlen($s);
        for($i = 0; $i < $n; $i++) 
            $ans ^= ord($s[$i]);
        
        return $ans;
    }
    
    function findTheDifference($s, $t) {
        
        $ans = 0;
        
        $ans ^= Solution::getXor($s);
        $ans ^= Solution::getXor($t);

        return chr($ans);
    }
}