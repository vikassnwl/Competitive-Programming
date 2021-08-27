#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

int ar[1e6];
int st[4e6];

int sum(int a, int b){
	return a+b;
}

void buildTree(int si, int ss, int se){
	if(ss==se){
		st[si] = ar[ss];
		return;
	}
	int mid = (ss+se)/2;
	buildTree(2*si, ss, mid);
	buildTree(2*si+1, mid+1, se);
	st[si] = sum(st[2*si], st[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe){
	if(ss>qe or se<qs) return 0;
	if(ss>=qs and se<=qe) return st[si];
	int mid = (ss+se)/2;
	return sum(query(2*si, ss, mid, qs, qe), query(2*si+1, mid+1, se, qs, qe));
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	//RSP using Segment Tree
	int n, q;
	cin>>n>>q;
	for(int i=0; i<n; i++)
		cin>>ar[i];
	buildTree(1, 0, n-1);
	while(q--){
		int l, r;
		cin>>l>>r;
		l--, r--;
		cout<<query(1, 0, n-1, l, r)<<endl;
	}
}
