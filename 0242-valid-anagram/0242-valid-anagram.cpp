class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int n1=t.size();
        unordered_map<char,int>mp;
        unordered_map<char,int>mp1;
        if(n!=n1){
            return false;
        }
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            mp1[t[i]]++;
        }
        return mp==mp1;
    }
};