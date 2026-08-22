class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int  i = nums1.size()-1;
       int j = nums2.size()-1;
       cout << m << i<< j ;
        while(n>0){
            if(i >= 0 && j >= 0 && nums1[i]== 0){
                nums1[i] = nums2[j] ;
                n-- ;
                i--;
                j--;
            }
            else if(nums1.empty() || nums2.empty() ) break ; 
        }
        std::sort(nums1.begin(), nums1.end());
        
    }
};