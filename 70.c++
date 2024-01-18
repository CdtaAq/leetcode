class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        function<int(int)> f=[&](int n)->int{
            if (dp[n]!=-1) return dp[n];
            if (n<=2) return dp[n]=n;
            return dp[n]=f(n-1)+f(n-2);
        };
        return f(n);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
