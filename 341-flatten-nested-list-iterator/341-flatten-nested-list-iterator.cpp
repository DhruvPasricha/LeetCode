/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

vector<int> flatten(vector<NestedInteger> &nestedList) {
    
    vector<int> nums;
    
    for(auto &cur : nestedList) {
        
        if(cur.isInteger()) {
            nums.push_back(cur.getInteger());
        } else {
            auto temp = flatten(cur.getList());
            nums.insert(nums.end(), temp.begin(), temp.end());
        }
    }
    
    return nums;
    
}

class NestedIterator {
    vector<int> nums;
    int it = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        nums = flatten(nestedList);
    }
    
    int next() {
        return nums[it++];
    }
    
    bool hasNext() {
        return it < nums.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */