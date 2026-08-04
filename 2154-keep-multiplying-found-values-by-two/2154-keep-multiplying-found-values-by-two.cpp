class Solution {
public:
    int findFinalValue(vector<int>& nums, int org) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==org){
                org=org*2;
            }
        }
        return org;
    }
};