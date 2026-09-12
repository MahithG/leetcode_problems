class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char>mpp ;
        erase(key,' ');
        char ch = 'a' ;
       for(int i = 0; i < key.size(); i++){
        if(key[i] == ' ') continue;
        if(mpp.find(key[i]) == mpp.end()){
        mpp[key[i]] = ch;
        ch++;
    }
    }
        for(auto it :mpp){
            cout <<it.first << "link" << it.second << endl ;
        }
        for(int i =0;i<message.size();i++){
            if(message[i] == ' ') continue ;
            message[i] = mpp[message[i]] ;
        }


    return message ;}
};