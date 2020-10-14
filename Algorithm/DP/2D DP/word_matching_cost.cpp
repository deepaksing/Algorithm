//find the minimum number of operations to make two words same

//for example: 
// SNOWY and SUNNY
// ----->  we need 3 opertaions to make sunny from snowy

//operation 1: insert U at position 1 (0 based index)  so SNOWY -> SUNOWY
//operation 2: substitute O to N at position 3 so SUNOWY -> SUNNWY
//operation 3: delete W from position 4 SUNNWY -> SUNNY



#include<bits/stdc++.h>

#define int long long
#define endl "\n"

#define pb push_back
#define F first
#define S second

#define vi(a, n) vector<int> a(n)
#define ai(a, n) int a[n];
#define arrayin(a,n) for(int i=0; i<n; i++) cin>>a[i]
#define f(i, n) for(int i = 0; i<n; i++)
#define fr(i, k, n) for(int i = k; i<n; i++)

#define MOD 1e9+7

using namespace std;

int32_t main() {

    string s1,s2;
    cin>>s1>>s2;

    int n = s1.length();
    int m = s2.length();

    int dp[n+1][m+1];

    for(int i=0; i<n; i++) dp[i][0] = i;
    for(int i=0; i<n; i++) dp[0][i] = i;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int diff = 1;
            if(s1[i-1] == s2[j-1]) diff = 0;

            dp[i][j] = min(1 + dp[i-1][j], min(1+dp[i][j-1], diff + dp[i-1][j-1]));
        }
    }

    cout<<dp[n][m]<<endl;
    
    return 0;
}