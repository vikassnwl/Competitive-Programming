#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
#define BLOCK 317
using namespace std;
 
int ar[100000];
 
struct query{
	int l;
	int r;
	int i;
};
query Q[100000];
int fre[100001];
int freOfFre[100002];
int res[100000];
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
 
	if(curF > maxF)
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
 
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, q;
	cin>>n>>q;
	for(int i=0; i<n; i++)
		cin>>ar[i];
	for(int i=0; i<q; i++)
		cin>>Q[i].l>>Q[i].r, Q[i].i=i;
	sort(Q, Q+q, comp);
 
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
 
		res[Q[i].i] = maxF;
	}
 
	for(int i=0; i<q; i++)
		cout<<res[i]<<endl;
}
