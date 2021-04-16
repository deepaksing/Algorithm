// 0-1 knapsack

#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

//BRUTE FORCE RECURSIVE

int knapsack(int w, int val[], int wt[], int n) {
    //base case
    if(n < 0 || w <= 0) return 0;

    //running case of the code
    
    if(wt[n] <= w) {
        return max((val[n]+knapsack(w-wt[n], val, wt, n-1)), knapsack(w, val, wt, n-1));
    }
    else return knapsack(w, val, wt, n-1);
}

//DP memoized version.

const int N = 1e2;

int dp[N][N];
int knapsack(int w, int val[], int wt[], int n) {
    if(n <0 || w<=0) return 0;

    if(dp[w][n] != -1) return dp[w][n];

    if(wt[n]<= w) {
        return dp[w][n] = max((val[n]+knapsack(w-wt[n], val, wt, n-1)), knapsack(w, val, wt, n-1));
    }
    else return dp[w][n] = knapsack(w, val, wt, n-1);
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i=0; i<N; i++) {
        for(int j =0; j<N; j++) {
            dp[i][j] = -1;
        }
    }

    // for(int i=0; i<=N; i++) dp[i][0] = 0;

    // for(int i=0; i<=N; i++) dp[0][i] = 1;

    int val[n], wt[n];
    int weight;
    cin>>weight;
    
    for(int i=0; i<n; i++) cin>>wt[i];
    for(int i=0; i<n; i++) cin>>val[i];

    
    cout<<knapsack(weight, val, wt, n-1)<<endl;

    return 0;

}