class Solution {
    
    function getSum($num) {
        
        if($num == 0) return 0;
        
        return ($num % 10) + Solution::getSum(floor($num / 10)); 
        
    }
    
    function addDigits($num) {
        
        $sum = Solution::getSum($num);
        
        if($sum < 10) return $sum;
        
        return Solution::addDigits($sum);
    }
}