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

struct Trie{
	map<char, Trie*> mp;
};

Trie* getNode(){
	Trie* node = new Trie;
	return node;
}

void insert(Trie *root, string s){
	Trie *tempRoot = root;
	for(char c: s){
		if(tempRoot->mp.find(c)==tempRoot->mp.end())
			tempRoot->mp[c] = getNode();
		tempRoot = tempRoot->mp[c];
	}
	tempRoot->mp['*'];
}

bool search(Trie *root, string s){
	Trie *tempRoot = root;
	for(char c: s){
		if(tempRoot->mp.find(c)==tempRoot->mp.end())
			return false;
		tempRoot = tempRoot->mp[c];
	}
	return tempRoot->mp.find('*')!=tempRoot->mp.end();
}

void solve(){
	Trie *root = getNode();
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
