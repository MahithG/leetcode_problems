class Solution {
public:
    int mySqrt(int x) {
        int i =1;
        while(true){
            long long sqrt = 1LL * i * i;
          if(x == sqrt){
            return i ;
          }
          else if(x<sqrt){
            return i-1 ;
          } i++;
        }
    return i ;}
};