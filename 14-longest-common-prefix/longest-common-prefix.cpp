class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        string s ="";
        for(int i =0 ;i<strs.size()-1;i++){
           string st ="";
           for(int j = 0;j<strs[i].size();j++){
                if(strs[i][j]==strs[i+1][j]){
                    st = st+strs[i][j] ;
                }
                else{
                    break ;
                }
           }
           if(i==0) s=st;
           if(st.size()<s.size() && i>0) s=st;
        }
        return s;
    }
};