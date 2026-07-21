class Solution {
public:
    bool check(vector<int>& nums) {
        int drop =0;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){drop ++ ;}
        }
        if(nums[0]<nums[nums.size()-1]){drop=drop+1;}
          if(drop>1){return false ;}
          else{return true;}
    }
};