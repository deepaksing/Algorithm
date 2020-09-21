#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int MOD = 1e9 + 7;
int m;

int recursive(vector<int> a, int n) {
     //recursive approach to problem
     if(n <= 0) return 0;
     int q = INT_MIN;
     for(int i=0; i<n; i++) {
          q = max(q, a[i] + recursive(a, n-i-1));
     }
     return q;
}

int mem_top_down(vector<int> a, int n, vector<int> &rods_price) {
     if(rods_price[n] >= 0) return rods_price[n]; //if there is a value previously then return that value as it is the best possible
     if(n <= 0) return 0;

     int q = INT_MIN;

     for(int i=0; i<n; i++) {
          q = max(q, a[i] + mem_top_down(a, n-i-1, rods_price));
     }
     rods_price[n] = q; // set the current rods price as q

     return rods_price[n];
}

int bottom_top(vector<int> a, int length, vector<int> &rod) {
     
     for(int i = 1; i<=length; i++) {
          int q = INT_MIN;
          for(int j = 0; j<i; j++) {
               q = max(q, a[j] + rod[i-j-1]);
          }
          rod[i] = q;
     }

     return rod[length];
}

int32_t main() {
     
     int n;
     cin>>n;
     m = n;

     vector<int> a(n);

     for(int i=0; i<n; i++) cin>>a[i];

     int length;
     cin>>length;

     cout<<"normal recursive approach : "<<recursive(a, length)<<endl;// works in 2 power n

     vector<int> rods_price(n);
     for(int i=0; i<n; i++) rods_price[i] = INT_MIN;
     cout<<"memoized top down approach : "<<mem_top_down(a, length, rods_price)<<endl; //works in n square

     vector<int> rod(n+1);
     rods_price[0] = 0;
     cout<<" bottom top approach : "<<bottom_top(a, length, rod)<<endl;//works in n square

     return 0;
}