class Solution {
public:
    bool rotateString(string s, string goal) {
        bool ans = false ;
        char c;
        int i=0;
        string str = s ;
        while( i < str.size()){
         if(str == goal){
            ans = true ;
            break;
         }
         c  = str.back();
         str.pop_back();
         str.insert(0,1,c);
         i++ ;
        }
   return ans ; }
};