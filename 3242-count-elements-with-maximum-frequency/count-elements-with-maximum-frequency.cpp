class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++ ;
        }
        int maxi = 0 ;
        for(auto it : mp){
            maxi = max(maxi,it.second);
        }
        int ans = 0;
        for(auto itt : mp){
        if(itt.second == maxi) ans += itt.second ;
        }

    return ans ;}
};