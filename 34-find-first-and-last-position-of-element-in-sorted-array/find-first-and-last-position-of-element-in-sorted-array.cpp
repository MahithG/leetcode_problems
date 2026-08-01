class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int first = 0;
   int last = nums.size()-1;
   int mid =0;
   int st = -1;
   int end = -1;
   while(first<=last){
  mid = (first + last)/2 ;
  if(nums[mid] == target ){
     st = mid ;
     last = mid-1;
  }
   else if(nums[mid] < target ){
    first = mid+1;
  }
  else if(nums[mid] > target ){
    last = mid -1 ;
  }
   }
   first = 0;
   last = nums.size()-1;
   while(first<=last){
  mid = (first + last)/2 ;
  if(nums[mid] == target ){
     end = mid ;
     first  = mid+1;
  }
   else if(nums[mid] < target ){
    first = mid+1;
  }
  else if(nums[mid] > target ){
    last = mid -1 ;
  }
   }
   
    return {st,end} ;}
};