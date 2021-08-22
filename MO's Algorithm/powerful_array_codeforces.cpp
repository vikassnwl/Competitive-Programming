#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
#define BLOCK 500
using namespace std;

vector<int> v(200000);

struct query{
	int l;
	int r;
	int i;
};

vector<query> Q(200000);

ll power = 0;
vector<ll> res(200000);
vector<int> fre(1e6+1);

bool comp(query a, query b){
	if(a.l/BLOCK!=b.l/BLOCK)
		return a.l/BLOCK<b.l/BLOCK;
	return a.r<b.r;
}

void add(int pos){
	ll cnt = fre[v[pos]];	
	fre[v[pos]]++;
	power -= cnt*cnt*v[pos], cnt++;
	power += cnt*cnt*v[pos];
}

void remove(int pos){
	ll cnt = fre[v[pos]];
	fre[v[pos]]--;
	power -= cnt*cnt*v[pos], cnt--;
	power += cnt*cnt*v[pos];
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin>>n>>q;
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	for(int i=0; i<q; i++){
		cin>>Q[i].l, cin>>Q[i].r;	
		Q[i].i = i, Q[i].l--, Q[i].r--;
	}

	sort(Q.begin(), Q.begin()+q, comp);
	
	int ML = 0, MR = -1;

	for(int i=0; i<q; i++){
		int L = Q[i].l;
		int R = Q[i].r;

		while(ML<L)
			remove(ML), ML++;
		while(ML>L)
			ML--, add(ML);
		while(MR<R)
			MR++, add(MR);
		while(MR>R)
			remove(MR), MR--;
		
		res[Q[i].i] = power;
	}
	for(int i=0; i<q; i++){
		cout<<res[i]<<endl;
	}
}
