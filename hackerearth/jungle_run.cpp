#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long

int n;
char grid[30][30];
int dist[30][30], vis[30][30];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y){
	if(x<0||x>n-1||y<0||y>n-1||vis[x][y]||grid[x][y]=='T')
		return false;
	return true;
}

void bfs(int x, int y){
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = 1;
	while(!q.empty()){
		int currX, currY;
		tie(currX, currY) = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int newX = currX+dx[i];
			int newY = currY+dy[i];
			if(isValid(newX, newY)){
				q.push({newX, newY});
				vis[newX][newY] = 1;
				dist[newX][newY] = dist[currX][currY]+1;
			}
		}
	}
}

void solve(){
	cin>>n;
	pair<int, int> sp, ep;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>grid[i][j];
			if(grid[i][j]=='S') sp.first=i, sp.second=j;
			if(grid[i][j]=='E') ep.first=i, ep.second=j;
		}
	}
	bfs(sp.first, sp.second);
	cout<<dist[ep.first][ep.second];
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
