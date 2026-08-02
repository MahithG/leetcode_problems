class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
         int index;
        while(left<right){
            mid = (left+right)/2;
            if(nums[mid]>nums[right]){
                left = mid+1;
            }
            else{
                right = mid ;
            }
       } 
       index = left ;
       left = 0;
         right = index-1;
         mid = 0;
       int ind = -1;  
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]==target){
               return mid ;
            }
            else if(nums[mid]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        left = index;
         right = nums.size()-1;
         mid = 0;  
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]==target){
                return mid ;
            }
            else if(nums[mid]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

 return -1 ;}
};