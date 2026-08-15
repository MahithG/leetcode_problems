class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size() - 1;
        int count = 0;
        while(i >= 0 && s[i] == ' ') {
               i--;
          }
          s.erase(i + 1);
        for(int k = 0;k<s.size();k++){
            if(s[k] == ' ') count++;
            len++ ;
        }
        if(count == 0) return len ;
        len = 0;
        for(int j = s.size()-1;j>0;j--){
           if(s[j] == ' ') break ;
           len++ ;
        }
    return len ;}
};