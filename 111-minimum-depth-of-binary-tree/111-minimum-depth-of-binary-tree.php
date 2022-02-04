class Solution {
    
    
    private function isLeaf($root) {
        return $root->left == null && $root->right == null;
    }
    

    function minDepth($root) {
        
        if($root == null) 
            return 0;
        
        if($this->isLeaf($root)) 
            return 1;
        
        $leftDepth = ($root->left) ? $this->minDepth($root->left) : 1e6;
        $rightDepth = ($root->right) ? $this->minDepth($root->right) : 1e6 ;
        
        return 1 + min($leftDepth, $rightDepth);
    }
}