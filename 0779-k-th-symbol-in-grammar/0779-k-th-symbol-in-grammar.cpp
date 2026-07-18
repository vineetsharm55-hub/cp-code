class Solution {
public:
    int parity(int x){
        if(x==0)return 0;
        return 1-parity(x & (x-1));
    }
    int kthGrammar(int n, int k) {
        return parity(k-1);
    }
};