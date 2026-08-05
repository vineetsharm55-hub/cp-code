class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while(b > 0) {
            if(b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    int numberOfSequence(int n, vector<int>& sick) {

        int healthy = n - sick.size();

        vector<long long> fact(n + 1, 1);

      
        for(int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        long long ans = fact[healthy];

 
        int left = sick[0];

       
        int right = n - 1 - sick.back();

        ans = ans * power(fact[left], MOD - 2) % MOD;
        ans = ans * power(fact[right], MOD - 2) % MOD;


        
        for(int i = 1; i < sick.size(); i++) {

            int gap = sick[i] - sick[i - 1] - 1;

            if(gap > 0) {

                
                ans = ans * power(fact[gap], MOD - 2) % MOD;

                
                ans = ans * power(2, gap - 1) % MOD;
            }
        }

        return ans;
    }
};