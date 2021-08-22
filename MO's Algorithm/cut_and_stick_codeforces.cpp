#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
#define BLOCK 548
using namespace std;

struct query{
	int l;
	int r;
	int i;
};

query Q[300000];
int ar[300000];
int res[300000];
int fre[300001];
int freOfFre[300001];
int maxF = 0;

bool comp(query a, query b){
	if(a.l/BLOCK!=b.l/BLOCK)
		return a.l/BLOCK<b.l/BLOCK;
	return a.r<b.r;
}

void add(int pos){
	int preF = fre[ar[pos]];
	fre[ar[pos]]++;
	int curF = fre[ar[pos]];

	freOfFre[preF]--;
	freOfFre[curF]++;

	if(curF>maxF)
		maxF = curF;
}

void remove(int pos){
	int preF = fre[ar[pos]];
	fre[ar[pos]]--;
	int curF = fre[ar[pos]];

	freOfFre[preF]--;
	freOfFre[curF]++;

	while(freOfFre[maxF]==0)
		maxF--;
}

int solve(int maxF, int l, int r){
	int total = r-l+1;
	if(maxF<=(total+1)/2)
		return 1;
	return total-2*(total-maxF);
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin>>n>>q;
	for(int i=0; i<n; i++)
		cin>>ar[i];
	for(int i=0; i<q; i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].i=i, Q[i].l--, Q[i].r--;
	}
	sort(Q, Q+q, comp);
	int ML=0, MR=-1;
	for(int i=0; i<q; i++){
		int L = Q[i].l;
		int R = Q[i].r;

		while(MR<R)
			MR++, add(MR);
		while(ML<L)
			remove(ML), ML++;
		while(MR>R)
			remove(MR), MR--;
		while(ML>L)
			ML--, add(ML);

		res[Q[i].i] = solve(maxF, L, R);
	}
	for(int i=0; i<q; i++)
		cout<<res[i]<<endl;
}
