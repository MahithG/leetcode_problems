class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0 ;
        for(int i = 0;i<nums.size();i++){
            if(10<= nums[i] && nums[i] <=99) ans += 1 ;
            else if(1000<= nums[i] && nums[i] <=9999) ans += 1;
            else if(100000<=nums[i] && nums[i] <=999999) ans += 1 ;
            else{ 
                ans +=0;
            }
        }
    return ans ;}
};