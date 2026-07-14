class Solution {
public:
    bool canConstruct(string r, string m) {
        int n=r.size();
        int n1=m.size();
        map<char,int>mp;
        for(int i=0;i<n1;i++){
            mp[m[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[r[i]]>0){
                mp[r[i]]--;
            }else{
                return false;
            }
        }
        return true;
    }
};