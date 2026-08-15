class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int i =0;
         for(i =0;i<s.size()-1;i++){
            if(s[i] == 'I' &&(s[i+1] == 'V')){
                sum += 4 ;
                i = i+1;
            }
            else if(s[i] == 'I' &&(s[i+1] == 'X')){
                sum += 9 ;
                i = i+1;
            }
            else if(s[i] == 'X' &&(s[i+1] == 'L')){
                sum += 40 ;
                i = i+1;
            }
            else if(s[i] == 'X' &&(s[i+1] == 'C')){
                sum += 90 ;
                i = i+1;
            }
            else if(s[i] == 'C' &&(s[i+1] == 'D')){
                sum += 400 ;
                i = i+1;
            }
            else if(s[i] == 'C' &&(s[i+1] == 'M')){
                sum += 900 ;
                i = i+1;
            }
            else{
                if(s[i] == 'I') sum += 1;
                if(s[i] == 'V') sum += 5;
                if(s[i] == 'X') sum += 10;
                if(s[i] == 'L') sum += 50;
                if(s[i] == 'C') sum += 100;
                if(s[i] == 'D') sum += 500;
                if(s[i] == 'M') sum += 1000;
            }
            
            
         }
         cout << i ;
         if(s[i] == 'I') sum += 1;
         if(s[i] == 'V') sum += 5;
         if(s[i] == 'X') sum += 10;
         if(s[i] == 'L') sum += 50;
         if(s[i] == 'C') sum += 100;
         if(s[i] == 'D') sum += 500;
         if(s[i] == 'M') sum += 1000;
  

    return sum ;}
};