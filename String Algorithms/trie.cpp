#include<bits/stdc++.h>
using namespace std;

//================PBDS==================
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset =
tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
//======================================

#define endl '\n'
#define mod 1000000007
#define int long long

const int SIZE = 26;

struct node{
	bool endOfWord;
	node* ar[SIZE];
};

node* getNode(){
	node* n = new node;
	n->endOfWord = false;
	for(int i=0; i<SIZE; i++)
		n->ar[i] = NULL;
	return n;
}

void insert(node *root, string st){
	node *tempRoot = root;
	for(int i=0; i<st.size(); i++){
		int index = st[i]-'a';
		if(tempRoot->ar[index]==NULL)
			tempRoot->ar[index] = getNode();
		tempRoot = tempRoot->ar[index];
	}
	tempRoot->endOfWord = true;
}

bool search(node *root, string st){
	node *tempRoot = root;
	for(int i=0; i<st.size(); i++){
		int index = st[i]-'a';
		if(tempRoot->ar[index]==NULL)
			return false;
		tempRoot = tempRoot->ar[index];
	}
	return tempRoot->endOfWord;
}

void solve(){
	node *root = getNode();
	int n, code;
	string st;
	while(1){
		cin>>code;
		if(code==1){
			cout<<"Enter string to insert\n";
			cin>>st;
			insert(root, st);
		}
		else if(code==2){
			cout<<"Enter string to search\n";
			cin>>st;
			cout<<search(root, st)<<endl;
		}
		else break;
	}
}

signed main(){	
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	solve();
}
