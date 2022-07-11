#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int n;
char grid[3][101];
int vis[3][101];
int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

bool isValid(int x, int y){
	if(x<1||x>2||y<1||y>n||vis[x][y]||grid[x][y]=='1')
		return false;
	return true;
}

void bfs(int x, int y){
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = 1;
	while(!q.empty()){
		tie(x, y) = q.front();
		q.pop();
		for(int i=0; i<8; i++){
			int a = x+dx[i];
			int b = y+dy[i];
			if(isValid(a, b)){
				vis[a][b] = 1;
				q.push({a, b});
			}
		}
	}
}

void solve(){
	cin>>n;
	for(int i=1; i<=2; i++)
		for(int j=1; j<=n; j++){
			vis[i][j] = 0;
			cin>>grid[i][j];
		}
	bfs(1, 1);
	if(vis[2][n]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
		solve();
}
