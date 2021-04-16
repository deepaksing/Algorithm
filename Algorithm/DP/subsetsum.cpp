#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

int dp[10001][10001];

int ssum(int a[], int n, int sum) {
    if(sum == 0) return 1;
    if(n == 0) return 0;
    if(dp[sum][n] != -1) return dp[sum][n];
    
    if(a[n] <= sum) {
        return dp[sum][n] = ssum(a, n-1, sum-a[n])||ssum(a, n-1, sum);
    }
    else return dp[sum][n] = ssum(a, n-1, sum);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    memset(dp, -1, sizeof(dp));

    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    int sum;
    cin>>sum;

    cout<<ssum(a, n-1, sum)<<endl;

    return 0;

}