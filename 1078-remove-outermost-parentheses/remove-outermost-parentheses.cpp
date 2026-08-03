class Solution {
public:
    string removeOuterParentheses(string s) {
       int i = 0;
       int count = 0;
       int prev = 0 ;
       string st = s;
        while(i< st.size()){
            if(st[i]=='('){count ++ ;}
            else{count -- ;}
             if(count == 0){
            st.erase(i,1);
            st.erase(prev,1);
            i=i-2 ;
            prev = i+1 ;
             } i++ ;
        }
    return st ;}
};