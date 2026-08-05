class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;

        // Calculate total sum
        for (int num : nums) {
            totalSum += num;
        }

        // Find middle index
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};