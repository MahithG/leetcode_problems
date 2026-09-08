class Solution {
public:
    int countCommas(int n) {
        int ans = 0 ;
        int x = n ;
        if(x>999){
        for(int i = x ; i>999;i--){
         ans = ans+ 1 ;
        }
        }

    return ans; ;}
};