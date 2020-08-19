#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

//RABIN-KARP ALGORITHM
//O(n*m) time

const int size = 26;

int stringWeight(char p) {
    return (p - 'a' + 1);
}

int power(int w, int pC) {
    return w*pow(size, pC);
}

int32_t main() {
    
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;
        string p;
        cin>>p;
        int found = 0;

        int n = s.length();

        int pl = p.length();
        int pC = 0;
        
        int maxM = 1e8+7;

        int sum = 0;
        
        // hash number for pattern 
        for(int i=0;  i<pl; i++) {
            int w = stringWeight(p[i]);
            int mul =  power(w, pC)%maxM;
            sum = (sum + mul)%maxM;
            pC++;
        }
        int f = sum%maxM;

        //we have to search for f in the string
        int i=0;
       for(i; i<n; i++) {
            sum = 0;
            pC = 0;
            for(int j = 0; j<pl; j++) {
                int w = stringWeight(s[i+j]);
                int mul = power(w, pC)%maxM;
                sum = (sum + mul)%maxM;
                pC++;
            }
            if(sum == f) {
                found = 1;
                break;
            }
        }

        if(found) cout<<"ele found at "<<i+1<<endl;
        else cout<<"not found "<<endl;
    }
    return 0;
}