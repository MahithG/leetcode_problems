class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i =0 ;i<s.size();i++){
         ans += abs(s[i]-'z' -1)*(i+1) ;
        
        }
   return ans ; }
};