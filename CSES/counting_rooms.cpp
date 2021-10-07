#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long

int n, m;
char matrix[1000][1000];
int vis[1000][1000];

bool isValid(int x, int y){
	if(x<0||x>n-1||y<0||y>m-1)
		return false;
	if(vis[x][y] || matrix[x][y]=='#')
		return false;
	return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y){
	vis[x][y] = 1;
	for(int i=0; i<4; i++){
		if(isValid(x+dx[i], y+dy[i]))
			dfs(x+dx[i], y+dy[i]);
	}
}

void solve(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cin>>matrix[i][j];
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			if(!vis[i][j] and matrix[i][j]!='#')
				dfs(i, j), ans++;
	}
	cout<<ans;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
