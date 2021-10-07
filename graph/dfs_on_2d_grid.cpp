#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int N, M;
bool vis[1001][1001];

bool isValid(int x, int y){
	if(x<1||x>N||y<1||y>M)
		return false;
	if(vis[x][y]==true)
		return false;
	return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y){
	vis[x][y] = 1;
	cout<<x<<" "<<y<<endl;
	for(int i=0; i<4; i++){
		if(isValid(x+dx[i], y+dy[i]))
			dfs(x+dx[i], y+dy[i]);
	}
}

void solve(){
	cin>>N>>M;
	dfs(1, 1);
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
