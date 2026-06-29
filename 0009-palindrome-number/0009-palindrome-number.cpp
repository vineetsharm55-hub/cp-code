class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long r=0;
        int n=x;
        while(x!=0){
            int ri=x%10;
            r=r*10+ri;
            x=x/10;
        }
        if(n==r){
            return true;
        }
        else{
            return false;
        }     
    }
};