class Solution {
public:
    int countElements(vector<int>& nums) {

        int mini = nums[0];
        int maxi = nums[0];

        
        for(int i = 1; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != mini && nums[i] != maxi) {
                count++;
            }
        }

        return count;
    }
};