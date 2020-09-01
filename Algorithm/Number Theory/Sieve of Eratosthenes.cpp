

#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

//Sieve of Eratosthenes

int32_t main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> is_prime(n+1, 1);

        //0 and 1 are not prime numbers
        is_prime[0] = is_prime[1] = 0;

        for(int i=2; i<=n; i++) {
            if(is_prime[i] && i*i<=n && i%2) { 
                for(int j=i*i; j<=n; j+=i) {
                    is_prime[j] = 0;
                }
            }
        }

        for(int i=0; i<=n; i++) {
            if(is_prime[i]) {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    

    return 0;
}
