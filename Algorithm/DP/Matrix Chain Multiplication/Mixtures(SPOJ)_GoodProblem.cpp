#include<bits/stdc++.h>

#define int long long
#define endl "\n"
#define pb push_back

using namespace std;

int smoke[105][105];

int findans(int *a, int n) {
  
  int dp[n+1][n+1];
  int temp = INT_MAX;
  int r;
  memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++) dp[i][i] = 0;

    for(int length = 2; length<=n; length++) {

      //cout<<"l us : "<<length<<endl;
      for(int i=1; i<n-length+2; i++) {
        int val;
        int j = i+length-1;
        temp = INT_MAX;
        for(int k=i; k<j; k++) {
          //cout<<" ("<<i<<" "<<k<<") "<<" ("<<k+1<<" "<<j<<") "<<endl;
          val = dp[i][k] + dp[k+1][j];
          
          int sum = 0;
          for(int m=i; m<=k; m++) sum+=a[m-1];
          sum = sum%100;
          int sumr = 0;
          for(int m=k+1; m<=j; m++) sumr += a[m-1];
          sumr = sumr%100;
          //smoke
          val += (sum*sumr);
          temp = min(temp, val);
        }
        dp[i][j] = temp;

      }

    }


    return dp[1][n];
}

void solve() {

  int n;
  while (scanf("%lld", &n) != EOF) {
  int a[n];
  for(int i=0; i<n; i++) cin>>a[i];

  if(n==1) cout<<0<<endl;
  else if(n == 2) cout<<a[0]*a[1]<<endl;
  else cout<<findans(a, n)<<endl;
  }
}


int32_t main() {

    int t = 1;
    // cin>>t;

    while(t--) {
        solve();
        //solve2();
    }

    return 0;
}
