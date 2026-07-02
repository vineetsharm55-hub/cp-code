class Solution {
public:
    
void merge(vector<int>& nums,int i,int mid,int j){
    vector<int>temp;

    int left=i;
    int right=mid+1;
    while(left<=mid and right<=j){
        if(nums[left]<nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left++]);
    }
    while(right<=j){ 
        temp.push_back(nums[right++]);
    }
    for(int k=0;k<temp.size();k++){
        nums[i+k]=temp[k];
    }


}


void mergeSort(vector<int>& nums,int i,int j){
    if(i>=j) return;
    int mid=(i+j)/2;

    mergeSort(nums,i,mid);
    mergeSort(nums,mid+1,j);

    merge(nums,i,mid,j);
}

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;    
    }
};