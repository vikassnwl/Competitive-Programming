#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int dist[1001][1001];
int N, M;
int vis[1001][1001];

bool isValid(int x, int y){
	if(x<1||x>N||y<1||y>M)
		return false;
	if(vis[x][y])
		return false;
	return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int srcX, int srcY){
	queue<pair<int, int>> q;
	q.push({srcX, srcY});
	vis[srcX][srcY] = 1;
	dist[srcX][srcY] = 0;

	while(!q.empty()){
		int currX = q.front().first;
		int currY = q.front().second;
		q.pop();

		for(int i=0; i<4; i++)
			if(isValid(currX+dx[i], currY+dy[i])){
				int newX = currX+dx[i];
				int newY = currY+dy[i];

				q.push({newX, newY});
				vis[newX][newY] = 1;
				dist[newX][newY] = dist[currX][currY]+1;
			}
	}
	cout<<"Distance array\n";
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++)
			cout<<dist[i][j]<<" ";
		cout<<endl;
	}
}

void solve(){
	int x, y;
	cin>>N>>M;
	cin>>x>>y;
	bfs(x, y);
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
