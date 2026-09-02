class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int n = nums1.size();
       int oc = 0;
       int ec = 0;
       for(int i  =0 ;i<n;i++){
         if(nums1[i] %2 == 0) ec= ec+1;
         else{
            oc = oc+1;
         }
       }
       if(ec == n || oc == n) return true ;
       else return true ;

    return true ;}
};