class Solution {
public:
    string reverseWords(string s) {
        int pi = 0 ;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ' '){
            reverse(s.begin() + pi, s.begin() + i);
            pi = i+1 ;
            }
        }
        reverse(s.begin() + pi, s.end());
   return s ; }
};