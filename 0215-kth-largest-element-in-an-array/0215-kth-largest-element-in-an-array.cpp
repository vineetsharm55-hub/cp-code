class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> qt;

        for(auto it:nums){
            qt.push(it);
            if(qt.size()>k){
                qt.pop();
            }
        }
        return qt.top();
    }
};