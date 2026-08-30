class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int fmin=nums[0];
        int fmax = nums[0];
        int mini = 0;
        int maxi = 0;
        int ans = 0;
        for(int i=1;i<nums.size();i++){
          if(fmin>nums[i]){
             fmin = nums[i] ;
             mini = i;
          }
          if(fmax<nums[i]){
             fmax = nums[i] ;
             maxi = i ;
          } 
        }
    
        int x=min(mini,maxi);
        int y=max(mini,maxi);

        int a=y+1;
        int b=nums.size()-x;
        int c=x+1+nums.size()-y;

        ans=a;

        if(b<ans)
            ans=b;

        if(c<ans)
            ans=c;


  return ans ;  }
};