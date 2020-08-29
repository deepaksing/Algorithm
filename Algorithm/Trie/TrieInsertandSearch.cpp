#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

//trie implementation

class TrieNode {

    public:
        TrieNode *child[26];
        bool isEnd;

        TrieNode() {
            for(int i=0; i<26; i++) {
                child[i] = NULL;
            }
            isEnd = false;
        }
};

class Trie {
    public:
        TrieNode *root;

        Trie() {
            root = new TrieNode;
        }

        //inserting a word into the trie
        void insert(string word) {
            int n = word.length();
            TrieNode *temp = root;

            for(int i=0; i<n; i++) {
                int index = word[i] - 'a' + 1;
                if(!temp->child[index]) {
                    temp->child[index] = new TrieNode();
                }
                temp = temp->child[index];
            }
            //and after reaching last charachter of word set it as ending char

            temp->isEnd = true;
        }

        //searching for a word into the trie
        bool search(string word) {
            //logic is same as inserting the only difference is that instead of creating new node when we found an Null
            //we have to return false as the word is not present in the trie

            int n = word.length();
            TrieNode *temp = root;

            for(int i=0; i<n; i++) {
                int index = word[i] - 'a' + 1;
                if(!temp->child[index]) {
                    return false;
                }
                temp = temp->child[index];
            }
            //and after reaching last charachter of word set it as ending char

            return (temp->isEnd);
        } 
};

int32_t main() {
    
    Trie trie;

    trie.insert("apple");
    cout<<trie.search("apple")<<endl;   // returns true
    cout<<trie.search("app")<<endl;     // returns false
    trie.insert("app");   
    cout<<trie.search("app")<<endl;     // returns true

    return 0;
}