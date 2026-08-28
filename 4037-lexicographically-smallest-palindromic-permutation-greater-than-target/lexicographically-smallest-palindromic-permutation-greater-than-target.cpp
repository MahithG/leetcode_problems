
class Solution {
public:
    string lexPalindromicPermutation(string s,string target) {
        int n=s.size(),h=n/2,cnt[26]={};
        for(char c:s) cnt[c-'a']++;
        char mid=0;
        for(int i=0;i<26;i++){
            if(cnt[i]%2){
                if(mid) return "";
                mid='a'+i;
            }
            cnt[i]/=2;
        }
        auto build=[&](string left){
            string ans=left;
            if(n%2) ans+=mid;
            for(int i=h-1;i>=0;i--) ans+=left[i];
            return ans;
        };
        int rem[26];
        for(int i=0;i<26;i++) rem[i]=cnt[i];
        bool ok=true;
        for(int i=0;i<h;i++){
            int x=target[i]-'a';
            if(rem[x]==0){
                ok=false;
                break;
            }
            rem[x]--;
        }
        if(ok){
            string left=target.substr(0,h);
            string ans=build(left);
            if(ans>target) return ans;
        }
        for(int i=h-1;i>=0;i--){
            for(int j=0;j<26;j++) rem[j]=cnt[j];
            bool possible=true;
            for(int k=0;k<i;k++){
                int x=target[k]-'a';
                if(rem[x]==0){
                    possible=false;
                    break;
                }
                rem[x]--;
            }
            if(!possible) continue;
            int x=target[i]-'a';
            for(int j=x+1;j<26;j++){
                if(rem[j]==0) continue;
                rem[j]--;
                string left=target.substr(0,i);
                left+=char('a'+j);
                for(int k=0;k<26;k++)
                    left+=string(rem[k],char('a'+k));
                return build(left);
            }
        }
        return "";
    }
};
