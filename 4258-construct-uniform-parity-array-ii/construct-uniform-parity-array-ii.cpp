class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int o =0;
        int e  = 0;
        int so = INT_MAX;
        for(int i =0;i<nums1.size();i++){
            if(nums1[i]%2 == 0) e++ ;
            else {
                so = min(so,nums1[i]) ; 
                o++ ;
                }
        }
        if(o == 0 || e == 0 ) return true;
        for(int i =0;i<nums1.size();i++){
            if(nums1[i]%2 == 0){
                if(nums1[i]<so) return false ;
            }
        }
        

    return true;}
};