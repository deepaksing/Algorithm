//Question Link:  http://lightoj.com/volume_showproblem.php?problem=1004

//------------------------------------------------------SOLUTION: ---------------------------------------------------------

#include<bits/stdc++.h>
#define int long long
#define endl "\n"
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int N = 500 + 1;
 
int32_t main() {
    int t;
    cin>>t;
    int rec = 0;
   
    while(t--) {
        rec++;
        int n;
        cin>>n;
 
        vector<vector<int>> a(2*n-1);
 
       
        int dp[2*n-1][n];
        memset(dp, 0, sizeof(dp));
       
 
        int k = 0;
        int f = 0;
        for(int i=0; i<2*n-1; i++) {
            int r = k;
            k = (k+1);
            if(k > n) f = 1;
            if(f) k = r-1;
            a[i] = vector<int>(k);
            for(int j = 0; j<n; j++) {
                if(j<k) cin>>a[i][j];
                else {
                    dp[i][j] = -1;
                }
            }
        }
 
        dp[0][0] = a[0][0];
 
        for(int i=1; i<2*n-1; i++) {
            if(i <= n-1) {
                for(int j=0; j<a[i].size(); j++) {
               
                    if(dp[i-1][j] > 0)  dp[i][j] = dp[i-1][j] + a[i][j];
                    if(dp[i-1][j-1] > 0 && j>=1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i][j]);
                }
            }
            else  {
 
                for(int j=0; j<a[i].size(); j++) {
               
                    if(dp[i-1][j] > 0)  dp[i][j] = dp[i-1][j] + a[i][j];
                    if(dp[i-1][j+1] > 0 && j<n-1)dp[i][j] = max(dp[i][j], (dp[i-1][j+1] + a[i][j]));
                }
               
                   
            }
        }
 
        if(n == 0) cout<<"Case "<<rec<<": "<<0<<endl;
        else if(n == 1) cout<<"Case "<<rec<<": "<<dp[0][0]<<endl;
        else cout<<"Case "<<rec<<": "<<dp[2*n-2][0]<<endl;
 
    }
    return 0;
}
