#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;
    int hc;
};

Node* newNode(int key) {
    Node *node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}

void topview(Node* root) {
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    int hc = 0;
    root->hc = hc;
    map<int, int> m;
    
    while(!q.empty()) {
        hc = root->hc;
        if(m[hc] == 0) m[hc] = root->data;
        if(root->left) {
            root->left->hc = hc-1;
            q.push(root->left);
        }
        if(root->right) {
            root->right->hc = hc+1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
        
    }
    
    for(auto i: m) cout<<i.second<<" ";
    cout<<endl;
}

void solve() {
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);

    topview(root);
}

int32_t main() {
	int t = 1;
	//cin>>t;

	while(t--) {
		solve();
	}
	return 0;
}