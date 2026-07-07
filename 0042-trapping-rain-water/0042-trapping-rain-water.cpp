class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int lmax=0,rmax=0;
        int ans=0;
        for(int i=0;i<n;i++){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);

            if(lmax<rmax){
                ans+= lmax - height[i];
                l++;
            }
            else{
                ans+= rmax - height[i];
                r--;
            }
        }
        return ans;

    }
};