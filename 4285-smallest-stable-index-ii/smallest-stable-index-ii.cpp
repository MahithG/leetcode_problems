class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>minn(nums.size()) ;
        int maxx = INT_MIN ;
        int ins = 0;
        int ii = INT_MAX;
        minn[nums.size()-1] = nums[nums.size()-1] ;
        for(int i = nums.size()-2;i>=0;i--){
            minn[i] = min(nums[i],minn[i+1]);
        }
        for(int  i =0;i<nums.size();i++){
            maxx = max(nums[i],maxx);
            ins = maxx - minn[i] ;
            if(k>=ins) ii = min(ii,i) ;
        }
        if(ii == INT_MAX) return -1 ;
  return ii ;  }
};