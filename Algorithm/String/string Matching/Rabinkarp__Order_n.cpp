#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

//RABIN-KARP ALGORITHM

//O(n) time

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

        int sum1 = 0, sum2 = 0;
        
        // hash number for pattern and first pl charcters in the string 
        for(int i=0;  i<pl; i++) {
            int w1 = stringWeight(p[i]);
            int w2 = stringWeight(s[i]);
            int mul1 =  power(w1, pC)%maxM;
            int mul2 = power(w2, pC)%maxM;
            sum1 = (sum1 + mul1)%maxM;
            sum2 = (sum2 + mul2)%maxM;
            pC++;
        }
        //f is hash number for pattern
        int f = sum1%maxM;
        //q is hash number for first pl strings
        int q = sum2%maxM;


        int sum = 0;
        //we have to search for f in the string
        int i=0;
        if(f == q) {
            //first three charachters in the string is matching in pattern
            found = 1;
            cout<<"found at pos"<<1<<endl;
        }

        else {
           //search for pattern in the string 
           for(int i=pl; i<n; i++) {
               //rolling hash
               //--> what it does here is -->
               //h[i] = (h[i] - s[i-n])/size + s[i]*pow(size, n)
               // every time we remove first element from previously computed total hash value
               // so this gives us hash value without first element
               //now we add next element to the hash value
               //so every time we traverse to next elements with a particular length(which is equal to pattern size)
               //without using any extra loop  

               //this thing does the same 
               q = (q-(power(stringWeight(s[i-pl]), 0)))/26 + power(stringWeight(s[i]), pl-1);
               
               //if string and patten matches then break outside the loop and thats the answer
               if(q == f) {
                   found = 1;
                   cout<<"found at pos"<<i-pl+2<<endl;
                   break;
               }
           } 
        }

        //after traversing the whole string we are unable to find any pattern string
        if(found == 0) {
            cout<<"not found";
        }
    }
       
    return 0;
}