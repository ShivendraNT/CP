class Solution {
public:
    static const long long MOD=1e9+7;
    static const int MAX=5e5 +10;
    static vector<long long>fact,inv_fact;
    static long long power(long long x,long long y){
        long long ans=1;
        x%=MOD;
        while(y>0){
            if(y&1){
                ans=ans*x%MOD;
            }
            x=x*x%MOD;
            y>>=1;
        }
        return ans;
    }
    static void build() {
        if (!fact.empty()) return;      
        fact.assign(MAX, 1);
        for (int i = 1; i < MAX; i++)
            fact[i] = fact[i-1] * i % MOD;
        inv_fact.assign(MAX, 1);
        inv_fact[MAX-1] = power(fact[MAX-1], MOD-2);
        for (int i = MAX-2; i >= 0; i--)
            inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }

    int countValidSequences(int n, int k) {
        build();
        auto nCr=[&](long long a,long long b)->long long {
            if(b<0 || b>a || a<0){
                return 0;
            }
            return fact[a]*inv_fact[b]%MOD*inv_fact[a-b]%MOD;
        };
        long long total=nCr(n-1,k-1);
        long long odd=0;
        if(n-k>=0 && (n-k)%2==0){
            odd=nCr((n-k)/2 +k-1,k-1);
        }
        long long ans=(total-odd+MOD)%MOD;
        return (int)ans;
    }
    
};
vector<long long> Solution::fact;
vector<long long> Solution::inv_fact;
