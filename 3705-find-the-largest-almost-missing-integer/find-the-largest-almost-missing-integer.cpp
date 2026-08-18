class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> mp;
        int ans  = -1 ;
        for(int i =0;i<=nums.size()-k;i++){
            for(int j =i;j<i+k;j++){
                mp[nums[j]]++ ;
            }
            }
            for(auto it : mp){
                if(k == nums.size()){ ans = max(it.first,ans) ;}
                else if(it.second == 1){ans = max(it.first,ans) ;}
            }
        
     return ans ;}
};