class Solution {
public:
    int countSeniors(vector<string>& details) {
       int count = 0;
       for(int i =0;i<details.size();i++){
        if(details[i][11] == '7' || details[i][11] == '8' || details[i][11] == '9'){
            count ++ ;
        }
        if(details[i][11] == '6' && details[i][12] != '0'){
            count ++ ;
        }

       } 
   return count ; }
};