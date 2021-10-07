#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
vector<int> graph[10000];

bool isPrime(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true;
}

bool isValid(int u, int v){
	int cnt = 0;
	while(u){
		if(u%10!=v%10)
			if(++cnt>1) return false;
		u /= 10, v /= 10;
	}
	return true;
}

void solve(){
	int src, dst; cin>>src>>dst;
	int vis[10000];
	memset(vis, 0, sizeof vis);
	int dist[10000];
	memset(dist, -1, sizeof dist);
	queue<int> q;
	q.push(src);
	vis[src] = 1;
	dist[src] = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int child: graph[node]){
			if(!vis[child]){
				vis[child] = 1;
				q.push(child);
				dist[child] = dist[node]+1;
			}
		}
	}
	if(dist[dst]==-1) cout<<"Impossible"<<endl;
	else cout<<dist[dst]<<endl;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> primes;
	for(int i=1000; i<=9999; i++){
		if(isPrime(i)){
			primes.push_back(i);
		}
	}
	for(int i=0; i<primes.size(); i++){
		for(int j=i+1; j<primes.size(); j++){
			int u = primes[i], v = primes[j];
			if(isValid(u, v)){
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}
	}
	int t; cin>>t;
	while(t--)
		solve();
}
