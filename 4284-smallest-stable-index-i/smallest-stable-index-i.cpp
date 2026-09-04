class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int i =0;
        int instable = 0; 
        int ii = INT_MAX;
        while(i<nums.size()){
            int maxn = INT_MIN;
            int minn = INT_MAX;
            for(int j = 0;j<=i;j++){
               maxn = max(maxn,nums[j]);
            }
            for(int k = i;k<nums.size();k++){
               minn = min(minn,nums[k]);
            }
            instable = maxn-minn ;
            if(instable<=k){
              ii = min(i,ii);
            } i++;
        }
        if(ii == INT_MAX) ii = -1;
   return ii; }
};