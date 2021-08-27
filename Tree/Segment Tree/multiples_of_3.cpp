#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

int st[400000][3];
int lazy[400000];

void build(int si, int ss, int se){
	if(ss==se){
		st[si][0] = 1;
		return;
	}
	int mid = (ss+se)/2;
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);

	st[si][0] = st[2*si][0]+st[2*si+1][0];
}

void update(int si, int ss, int se, int qs, int qe){
	if(lazy[si]!=0){
		int dx = lazy[si]%3;
		lazy[si] = 0;
		for(int i=0; i<dx; i++){
			int temp = st[si][0];
			st[si][0] = st[si][2];
			st[si][2] = st[si][1];
			st[si][1] = temp;
		}

		if(ss!=se)
			lazy[2*si] += dx, lazy[2*si+1] += dx;
	}
	if(ss>qe or se<qs) return;
	if(ss>=qs and se<=qe){
		int temp = st[si][0];
		st[si][0] = st[si][2];
		st[si][2] = st[si][1];
		st[si][1] = temp;

		if(ss!=se)
			lazy[2*si] += 1, lazy[2*si+1] += 1;
		return;
	}
	int mid = (ss+se)/2;
	update(2*si, ss, mid, qs, qe);
	update(2*si+1, mid+1, se, qs, qe);

	st[si][0] = st[2*si][0]+st[2*si+1][0];
	st[si][1] = st[2*si][1]+st[2*si+1][1];
	st[si][2] = st[2*si][2]+st[2*si+1][2];
}

int query(int si, int ss, int se, int qs, int qe){
	if(lazy[si]!=0){
		int dx = lazy[si]%3;
		lazy[si] = 0;
		for(int i=0; i<dx; i++){
			int temp = st[si][0];
			st[si][0] = st[si][2];
			st[si][2] = st[si][1];
			st[si][1] = temp;
		}

		if(ss!=se)
			lazy[2*si] += dx, lazy[2*si+1] += dx;
	}
	if(ss>qe or se<qs) return 0;
	if(ss>=qs and se<=qe) return st[si][0];
	int mid = (ss+se)/2;

	return query(2*si, ss, mid, qs, qe)+query(2*si+1, mid+1, se, qs, qe);
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin>>n>>q;
	build(1, 0, n-1);

	while(q--){
		int type, l, r;
		cin>>type>>l>>r;
		if(type==0){
			update(1, 0, n-1, l, r);
		}
		else{
			cout<<query(1, 0, n-1, l, r)<<endl;
		}
	}
}
