// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//        for(int i=1;i<nums.size();i++){
//             if(nums[i]==nums[i-1]){
//                 return true;
//             }
//        }
//        return false;
//     }
// };
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_map<int,int>sp;
       int n=nums.size();
       for(int i=0;i<n;i++){
        if(sp.find(nums[i])!=sp.end()){
            return true;
        }
        sp[nums[i]]=i;
       }
       return false;
    }
};