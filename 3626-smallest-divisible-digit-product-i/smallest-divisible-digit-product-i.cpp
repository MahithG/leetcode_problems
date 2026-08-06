class Solution {
public:
    int smallestNumber(int n, int t) {
       int product = 1 ; 
       int x  = n ;
       while(true){ 
         n = x ;
         product = 1 ;
        while(n>0){
           product = product*(n%10) ;
           n = n/10 ;
        }
        if(product%t == 0){
            return x ;
        }
        else{ x = x+ 1 ;}
       
    }
     }
};