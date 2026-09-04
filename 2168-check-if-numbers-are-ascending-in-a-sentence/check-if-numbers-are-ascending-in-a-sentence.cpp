class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int>numst;
        for(int i = 0;i<s.size();i++){
            if((i == 0 || s[i-1]==' ')&&isdigit(s[i])){
                int num = 0;
                 while(i<s.size() && s[i] != ' ') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                } numst.push_back(num);

            }
        }
        for(int i = 0; i<numst.size();i++){
            cout << numst[i] << " ";
        }
        for(int i =0;i<numst.size()-1;i++){
            if(numst[i+1]<=numst[i]) return false ;
        }
   return true ; }
};