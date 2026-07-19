class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(auto i:nums){
            if(i==0) cnt++;
        }
        for(int i = 0;i<nums.size()-cnt;i++){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                i-- ;
            }
        } 
    }
};