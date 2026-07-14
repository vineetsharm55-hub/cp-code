class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int n1=nums2.size();
        map<int,int>mp;
        vector<int>ans;

        for(int i=0;i<n;i++){
            mp[nums1[i]]=1;

        }
        for(int i=0;i<n1;i++){
            if(mp[nums2[i]]==1){
                ans.push_back(nums2[i]);
            }
            mp[nums2[i]]=2;
        }
        return ans;
    }
};