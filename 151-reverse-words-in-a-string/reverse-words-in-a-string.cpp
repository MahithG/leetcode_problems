class Solution {
public:
    string reverseWords(string s) {
        int prev = 0;
        string ans = "" ;
        string st = s;
        bool hasSpace = false;
for(char c : s){
    if(c == ' '){
        hasSpace = true;
        break;
    }
}

if(!hasSpace)
    return s;
        for(int i =  st.size()-1;i>=0;i--){
            if(st[i]==' ' && (i==0 || i == st.size()-1 || st[i-1]!=' ')){
                prev = i-1 ;
            }
            if(( i==0  || st[i-1] ==' ') && st[i] != ' ' ){
                ans += st.substr(i,prev-i+1);
                ans += " " ;
            }
        } if (!ans.empty() && ans.back() == ' '){
            ans.pop_back(); }
    return ans ;}
};