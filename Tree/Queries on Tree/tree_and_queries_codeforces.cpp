#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

const int maxN = 100001;
const int BLK = 700;

int col[maxN], timer, S[maxN], T[maxN], FT[2*maxN], ans[maxN], nodeF[maxN], eleF[maxN], FF[maxN], bucket[maxN];
vector<int> tree[maxN];

void dfs(int node, int par){
	S[node] = timer;
	FT[timer] = node;
	timer++;
	for(int child: tree[node])
		if(child!=par) dfs(child, node);
	T[node] = timer;
	FT[timer] = node;
	timer++;
}

struct query{
	int l;
	int r;
	int idx;
	int k;
};

query Q[maxN];

bool comp(query a, query b){
	if(a.l/BLK!=b.l/BLK) return a.l/BLK<b.l/BLK;
	return a.r<b.r;
}

int getBlock(int idx){
	return idx/BLK;
}

void add(int idx){
	int node = FT[idx];
	nodeF[node]++;

	if(nodeF[node]==2){
		int c = col[node];
		eleF[c]++;
		FF[eleF[c]]++;
		bucket[getBlock(eleF[c])]++;
		FF[eleF[c]-1]--;
		bucket[getBlock(eleF[c]-1)]--;
	}
}

void remove(int idx){
	int node = FT[idx];
	nodeF[node]--;

	if(nodeF[node]==1){
		int c = col[node];
		eleF[c]--;
		FF[eleF[c]]++;
		bucket[getBlock(eleF[c])]++;
		FF[eleF[c]+1]--;
		bucket[getBlock(eleF[c]+1)]--;
	}
}

int getAns(int k, int n){
	int ans = 0;
	int LB = getBlock(k);
	int RB = getBlock(n);
	if(LB==RB){
		for(int i=k; i<=n; i++){
			ans += FF[i];
		}
	}
	else{
		for(int i=k; i<(LB+1)*BLK; i++){
			ans += FF[i];
		}
		
		for(int i=LB+1; i<RB; i++){
			ans += bucket[i];
		}

		for(int i=RB*BLK; i<=n; i++){
			ans += FF[i];
		}
	}
	return ans;
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q, a, b, k;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>col[i];
	
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	timer = 1;
	dfs(1, -1);

	for(int i=0; i<q; i++){
		cin>>a>>k;
		Q[i].idx = i;
		Q[i].k = k;
		Q[i].l = S[a];
		Q[i].r = T[a];
	}
	sort(Q, Q+q, comp);
	int ML = 1, MR = 0;
	for(int i=0; i<q; i++){
		int L = Q[i].l;
		int R = Q[i].r;
		k = Q[i].k;
		int idx = Q[i].idx;

		while(MR<R)
			MR++, add(MR);
		while(MR>R)
			remove(MR), MR--;
		while(ML<L)
			remove(ML), ML++;
		while(ML>L)
			ML--, add(ML);

		ans[idx] = getAns(k, n);
	}
	for(int i=0; i<q; i++)
		cout<<ans[i]<<endl;
}
