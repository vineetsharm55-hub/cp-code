class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums,
                                    vector<vector<int>>& queries) {
        
        int evenSum = 0;

        // Calculate initial sum of even numbers
        for (int num : nums) {
            if (num % 2 == 0) {
                evenSum += num;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int val = q[0];
            int index = q[1];

            // Remove old value if it was even
            if (nums[index] % 2 == 0) {
                evenSum -= nums[index];
            }

            // Update value
            nums[index] += val;

            // Add new value if it is even
            if (nums[index] % 2 == 0) {
                evenSum += nums[index];
            }

            ans.push_back(evenSum);
        }

        return ans;
    }
};