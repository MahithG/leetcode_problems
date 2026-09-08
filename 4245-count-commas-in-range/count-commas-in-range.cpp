class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        int ans = 0 ;
        int x = n ;
        while(n>999){
            n = n/10;
            count++ ;
        }
        cout<<count ;
        if(count>0){
        for(int i = x ; i>999;i--){
         ans = ans+ 1 ;
        }
        }

    return ans; ;}
};