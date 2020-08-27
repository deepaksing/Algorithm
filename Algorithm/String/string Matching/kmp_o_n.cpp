#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

//KNUTH MORRIS PRATT ALGORITHM(KMP ALGO)
//O(m+n) time  --> O(n)

//make the lps array

void lps_array(string pattern, vector<int> &lps) {
    int len = 0;
    int m = pattern.length();

    int i=1; 
    
    //first element in lps array starts from zero
    lps[0] = 0;
    while(i<m) {
        
        //if the charachter matches then give it an value +1
        if(pattern[i] == pattern[len]) {
            //increment the length
            len++;
            lps[i] = len;
            i++; 
        }

        //if dosent matches
        else {
            //and len == 0 then lps[i] = 0 and i is incremented
            if(len == 0) {
                lps[i] = 0;
                i++;
            }

            //if it doesent matches and len != 0
            //then we need to make len = lps[len-1]
            else {
                len = lps[len-1];
                //we havent incremented i here
                //this will do is that -->
                //it will look for same value of i with different value of len until len == 0
                //and if pattern matches then lps[i] will be set to that value
            }
        }
    }

    
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

        int pl = p.length(); // length of pattern 
        int n = s.length(); //length of string

        //1. we need to make an lps array of the pattern
        //2. then apply the logic to the string ...

        vector<int> lps(pl);
        lps_array(p, lps);

         //we get the lps array so now we can search for pattern in string

        int k = 0;
        int i=0;
        while(i<n) {
            if(s[i] == p[k]) {
                i++;
                k++;
            }
            //if we reach the last position in the lps array that 
            //means all charachter before it are satisified
            //and also at pos k
            //so (i-k+1) is the position where pattern in found
            //srting pos - length of pattern +1(as it started from 0)
            if(k == pl) {
                found = 1;
                cout<<"found at : "<<i-k+1<<endl;
                k = lps[k-1];
            }

            //if char is not matched then move to the previous prefix in the pattern 
            //by using lps array

            else if(i<n && s[i] != p[k]) {
                //check lps[k]
                //if k = 0 i.e lps[k] = 0
                //so we can not go anymore backwards in the lps array
                //i is incremented
                if(k == 0) {
                    i++;
                }
                //else just take the value at that lps[k-1]
                //so now this is the idex of k from where we will check with the string
                //
                else {
                    k = lps[k-1];
                }
            }
        }

        if(found == 0) {
            cout<<"not found"<<endl;
        }

    }      
    return 0;
}