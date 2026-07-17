// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n=nums.size();
//         int a=0;
//         int b=0;
//         for(int i=0;i<n;i++){
//             a=a+nums[i];
//         }
//         for(int i=0;i<=n;i++){
//             b=b+i;
//         }
//         int c=b-a;
//         return c;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int XOR=nums.size();
        for(int i=0;i<n;i++){
            XOR ^=i;
            XOR ^=nums[i];
        }
        return XOR;
    }
};