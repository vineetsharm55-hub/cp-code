class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int sum = 0;

        // Sum of first window
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Slide the window
        for(int i = k; i < nums.size(); i++) {

            sum = sum - nums[i - k] + nums[i];

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};

// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {

//         double maxi = INT_MIN;

//         for(int i = 0; i <= nums.size() - k; i++) {

//             int sum = 0;

//             for(int j = i; j < i + k; j++) {
//                 sum += nums[j];
//             }

//             maxi = max(maxi, (double)sum / k);
//         }

//         return maxi;
//     }
// };