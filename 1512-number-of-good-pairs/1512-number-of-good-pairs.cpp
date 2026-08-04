class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        int freq[101] = {0};
        int ans = 0;

        for (int num : nums) {
            ans += freq[num];
            freq[num]++;
        }

        return ans;
    }
};