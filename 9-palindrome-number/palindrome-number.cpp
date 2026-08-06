class Solution {
public:
    bool isPalindrome(int x) {
        long long y = 0 ;
        int x1 = x ;
        bool ans = false ;
        while(x>0){
          y = 10*y + x%10 ;
          x = x/10 ;
        }
        if(x1 == y) {ans = true ;}
   return ans ; }
};