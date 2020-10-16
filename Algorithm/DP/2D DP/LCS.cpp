//Longest Common Subsequence(LCS)

//eg: -> 
// AGGTAB
// GXTXAYB

//4
// number of times our function is called without memoization : 45
// function called after memoization : 25
 

#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

int max(int a, int b)  
{  
    return (a > b)? a : b;  
} 

//recursive approach (Normal)
int lcs(string s1, string s2, int n, int m) {
    if(n == 0 || m ==0)//so we cant check for any subsequnce
        return 0;
    if(s1[n-1] == s2[m-1]) //both equal so just increase lcs count by 1 
        return 1 + lcs(s1, s2, n-1, m-1);
    else
        return max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
}

//recursive(memoized) 

int dp[1005][1005];
int l=0,r=0;
int recm(string s1, string s2, int n, int m) {
    l++;
    if(n == 0 || m == 0) dp[n][m] = 0;
    if(dp[n][m] != -1) return dp[n][m];
    r++;
    if(s1[n-1] == s2[m-1]) dp[n][m] = 1 + recm(s1, s2, n-1, m-1);
    else dp[n][m] = max(recm(s1, s2, n-1, m), recm(s1, s2, n, m-1));
    return dp[n][m];
}

//topdown approach

int topdown(string s1, string s2, int n, int m) {

    int dp[n+1][m+1];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if( i==0 || j==0 ) dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int32_t main() {

    string s1,s2;
    cin>>s1>>s2;

    memset(dp, -1, sizeof(dp));

    int n,m;
    n = s1.length();
    m = s2.length();

    cout<<" --- normal recursive approach --------"<<endl;
    cout<<lcs(s1, s2, n, m)<<endl<<endl;
    cout<<" --- memoized recursive approach --------"<<endl;
    cout<<recm(s1, s2, n, m)<<endl<<endl;
    cout<<"number of times our function is called without memoziation : "<<l<<endl<<"function called after memoization : "<<r<<endl;
    cout<<" --- topdown approach --------"<<endl;
    cout<<topdown(s1, s2, n, m)<<endl;
    
    return 0;
}
