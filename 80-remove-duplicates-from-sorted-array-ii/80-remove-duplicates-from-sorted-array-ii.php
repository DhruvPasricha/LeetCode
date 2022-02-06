class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        
        $i = 0;
        $j = 0;
        $n = count($nums);
        
        while($j < $n) {
            
            $count = 0;
            $current = $nums[$j];
            
            while($j < $n and $nums[$j] == $current and $count < 2) {
                $nums[$i++] = $current;
                $count++;
                $j++;
            }
            
            while($j < $n and $nums[$j] == $current) {
                $j++;
            }
            
        }
        
        return $i;
    }

}