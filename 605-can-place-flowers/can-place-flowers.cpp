class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int prev = -1 ;
       int next = -1 ;
       int i = 0;
       if(flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1) return true ;
       if(flowerbed.size() >= 2 && flowerbed[0] == 0 && flowerbed[1] == 0){
        flowerbed[0] = 1;
        n-- ;
       }
       if(flowerbed.size() >= 2 &&flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0){
        flowerbed[flowerbed.size()-1] = 1;
        n-- ;
       }
    for(int i =1;i<flowerbed.size()-1;i++){
        prev = flowerbed[i-1];
        next = flowerbed[i+1] ;
        if(prev == 0 && flowerbed[i] == 0 &&next == 0 ){
            flowerbed[i] = 1;
            n--;}
    }
    if(n<= 0) return true ;
    else return false;
    }
};