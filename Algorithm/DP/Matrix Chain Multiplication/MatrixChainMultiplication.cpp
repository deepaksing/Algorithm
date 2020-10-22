#include<bits/stdc++.h>

#define int long long
#define endl "\n"
#define pb push_back

using namespace std;

int dp[10005][10005];

//recursive memoized 
int matrixchainmultime(int a[], int i, int j) {
  if(i==j) {
    dp[i][j] = 0;
    return 0;
  }
  if(dp[i][j] != -1) return dp[i][j];
  int ans = INT_MAX;
  for(int k=i; k<j; k++) {
    int val = matrixchainmultime(a, i, k) + matrixchainmultime(a, k+1, j) + a[i-1]*a[k]*a[j];
    if(val < ans) ans = val;
  }
  dp[i][j] = ans;
  return ans;
  
}

//recursive
int matrixchainmultisi(int a[], int i, int j) {
  if(i==j) return 0;
  int ans = INT_MAX;
  for(int k=i; k<j; k++) {
    int val = matrixchainmultisi(a, i, k) + matrixchainmultisi(a, k+1, j) + a[i-1]*a[k]*a[j];
    if(val < ans) ans = val;
  }
  return ans;
  
}

int matrixchainmultibottomup(int a[], int n) {
    int dp[n][n];
  int r;
    for(int i=1; i<n; i++) dp[i][i] = 0;

    //length here is started from 2 because for length =1 we have already assigned zero value
    for(int length = 2; length<n; length++) {

      for(int i=1; i<=n-length+1; i++) {
        int j = i+length-1;

        dp[i][j] = INT_MAX;
        for(int k=i; k<j; k++) {
          r = dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j];

          if(r < dp[i][j]) dp[i][j] = r;
        }
      }

    }

    return dp[1][n-1];
}

void solve() {

    int a[] = {1,2, 3, 4};
    int n = sizeof(a)/sizeof(a[0]);

    memset(dp, -1, sizeof(dp));

    
    cout<<"minimum cost for matrix chain multiplication without memoization : "<<endl;
    cout<<matrixchainmultisi(a, 1,n-1)<<endl;  
    cout<<"minimum cost for matrix chain multiplication with memoization : "<<endl;
    cout<<matrixchainmultime(a, 1,n-1)<<endl;  
    cout<<"minimum cost for matrix chain multiplication bottom up approach : "<<endl;
    cout<<matrixchainmultibottomup(a, n)<<endl;  

}

int32_t main() {

    int t = 1;
    //cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}
