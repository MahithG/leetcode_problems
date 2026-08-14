class Solution {
public:
    int maximumLengthSubstring(string s) {
        int length = 0;
        int maxl = 0;
        for(int i =0;i<s.size();i++){
            length = 0;
            map<char,int>mp;
            for(int j=i;j<s.size();j++){
                 mp[s[j]]++ ;
               if(mp[s[j]]>2) break ;
            
            length ++ ;
             maxl = max(length,maxl);
            }
           
        }
   return maxl ; }
};