class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        map<int,int> mp;

        for(int i = 0; i < digits.size(); i++){
            mp[digits[i]]++;
        }

        int ans = 0;

        for(auto i : mp){              // first digit
            if(i.first == 0)
                continue;

            for(auto j : mp){          // second digit
                for(auto k : mp){      // third digit

                    if(k.first % 2 != 0)
                        continue;

                    map<int,int> temp;

                    temp[i.first]++;
                    temp[j.first]++;
                    temp[k.first]++;

                    bool flag = true;

                    for(auto x : temp){
                        if(x.second > mp[x.first]){
                            flag = false;
                            break;
                        }
                    }

                    if(flag)
                        ans++;
                }
            }
        }

        return ans;
    }
};