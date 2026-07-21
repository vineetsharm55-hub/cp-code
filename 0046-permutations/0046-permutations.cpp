class Solution {
public:
    void getbacktrack(vector<int>&nums,int idx,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back({nums});
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);   
            getbacktrack(nums,idx+1,ans);
            swap(nums[i],nums[idx]);       //backtracking (always writen after function call)
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        getbacktrack(nums,0,ans);
        return ans;
        
    }
};