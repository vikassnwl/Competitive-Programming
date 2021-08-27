#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;
 
int ar[30000];
vector<int> st[120000];
 
void build(int si, int ss, int se){
	if(ss==se){
		st[si].push_back(ar[ss]);
		return;
	}
	int mid = (ss+se)/2;
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);
 
	int i = 0;
	int j = 0;
	while(i<st[2*si].size() and j<st[2*si+1].size()){
		if(st[2*si][i]<st[2*si+1][j]) st[si].push_back(st[2*si][i]), i++;
		else st[si].push_back(st[2*si+1][j]), j++;
	}
 
	while(i<st[2*si].size()) st[si].push_back(st[2*si][i]), i++;
	while(j<st[2*si+1].size()) st[si].push_back(st[2*si+1][j]), j++;
}
 
int query(int si, int ss, int se, int qs, int qe, int k){
	if(ss>qe or se<qs) return 0;
	if(ss>=qs and se<=qe){
		int res = st[si].end()-lower_bound(st[si].begin(), st[si].end(), k+1);
		return res;
	}
	int mid = (ss+se)/2;
	int l = query(2*si, ss, mid, qs, qe, k);
	int r = query(2*si+1, mid+1, se, qs, qe, k);
 
	return l+r;
}
 
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>ar[i];
	build(1, 0, n-1);
	int q;
	cin>>q;
	while(q--){
		int l, r, k;
		cin>>l>>r>>k;
		l--, r--;
		cout<<query(1, 0, n-1, l, r, k)<<endl;
	}
}
