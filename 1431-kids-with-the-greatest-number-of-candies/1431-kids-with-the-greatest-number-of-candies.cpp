class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& nums, int ext) {

        vector<bool> ans;

        for(int i = 0; i < nums.size(); i++) {

            bool check = true;

            for(int j = 0; j < nums.size(); j++) {

                if(nums[i] + ext < nums[j]) {
                    check = false;
                    break;
                }
            }

            ans.push_back(check);
        }

        return ans;
    }
};