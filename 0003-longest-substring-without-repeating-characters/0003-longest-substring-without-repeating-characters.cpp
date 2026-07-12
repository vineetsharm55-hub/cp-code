class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dist(256,-1);
        int maxLen=0,start=-1;
        for(int i=0;i<s.size();i++){
            if(dist[s[i]]>start){
                start=dist[s[i]];
            }
            dist[s[i]]=i;
            maxLen=max(maxLen,i-start);

        }
        return maxLen;
        
    }
};