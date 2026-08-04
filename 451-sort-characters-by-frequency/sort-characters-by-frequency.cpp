class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp ;
        string st = "";
        for(int i =0;i<s.size();i++){
            mpp[s[i]]++ ;
        }
         vector<pair<char, int>> v(mpp.begin(), mpp.end());

        // Sort according to frequency (descending)
        sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second > b.second;
        });

        for(auto it : v){
          st += string(it.second, it.first); ;
        }
   return st ; }
};