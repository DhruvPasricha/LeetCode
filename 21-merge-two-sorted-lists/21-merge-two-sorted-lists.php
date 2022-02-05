class Solution {

     function insert(&$x, &$head, &$tail) {
        
        if($head == null) 
            $head = $x;
        else 
            $tail->next = $x;
        
        $tail = $x;
        $x = $x->next;
        
    }
    
    function mergeTwoLists($list1, $list2) {
        if($list1 == null) return $list2;
        if($list2 == null) return $list1;
        
        $head = null;
        $tail = null;
        
        while($list1 and $list2) {
            if($list1->val <= $list2->val) 
                Solution::insert($list1, $head, $tail);
            else 
                Solution::insert($list2, $head, $tail);
        }
        
        if($list1 == null) $tail->next = $list2;
        if($list2 == null) $tail->next = $list1;
        
        return $head;
        
    }
}