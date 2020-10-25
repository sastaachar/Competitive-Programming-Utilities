class Solution {
public:
    
    int bs(vector<int>& nums, int target, int l, int r) {
        cout << l << " " << r  <<"\n";
        if(l > r)
            return -1;
        
        int mid = l + (r-l)/2;
        
        if(nums[mid] == target) 
            return mid;
        int cur = nums[mid];
         if(nums[0] <= cur) {
            // 0 to mid is sorted in asc
            // all bigger numbers are on right
             // for smaller it depends
                // 0 is smallest here 
             if(target > cur ) {
                 //go right
               return bs(nums, target, mid+1,r);
                 
             } else {
                 // go left
                if(nums[0] > target)
                    return bs(nums, target, mid+1,r);
                else 
                    return bs(nums, target, l,mid-1);
             }
             
             
                 
         } else {
             // mid to end is sorted in asc
             // smaller are in left
             // for bigger it depends
                // end is the highest we have
             
             if(target < cur) {
                 return bs(nums, target, l , mid-1);
             } else {
                 
                if(target > nums[nums.size()-1]) 
                    return bs(nums, target, l , mid-1);
                 else 
                    return bs(nums, target, mid+1, r);
             }
             
             
         }
            
        
        return -1;
        
    }   
    
    int search(vector<int>& nums, int target) {
        return      bs(nums,target, 0, nums.size()-1);
    }
};

/*
    //minified code
    class Solution {
public:
    
    
    
    int search(vector<int>& nums, int target) {
        
        int l=0, r = nums.size()-1, cur, mid;
        
        while(l <= r ) {
            mid = l + (r-l)/2;
            cur = nums[mid];
            if(cur == target)
                return mid;
            if((nums[0] <= cur && 
                (target > cur || nums[0] > target) ) || 
                (nums[0] > cur &&
                    (target >= cur && 
                     target <= nums[nums.size()-1]) ) ) 
                l = mid+1;            
             else
                r = mid-1;

            
        }
        return -1;
    }
};
*/