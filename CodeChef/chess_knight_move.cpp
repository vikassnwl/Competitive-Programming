#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int n, endX, endY;
int dist[9][9], vis[9][9];
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

bool isValid(int x, int y){
	if(x<1||x>8||y<1||y>8||vis[x][y])
		return false;
	return true;
}

int bfs(int x, int y){
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = 1;
	dist[x][y] = 0;
	while(!q.empty()){
		int currX, currY;
		tie(currX, currY) = q.front();
		q.pop();
		for(int i=0; i<8; i++){
			int newX = currX+dx[i];
			int newY = currY+dy[i];
			if(isValid(newX, newY)){
				if(newX==endX and newY==endY)
					return dist[currX][currY]+1;
				q.push({newX, newY});
				dist[newX][newY] = dist[currX][currY]+1;
				vis[newX][newY] = 1;
			}
		}
	}
	return 0;
}

void solve(){
	memset(vis, 0, sizeof vis);
	string s, e; cin>>s>>e;
	int srcX = s[0]-96, srcY = s[1]-'0';
	endX = e[0]-96, endY = e[1]-'0';
	cout<<bfs(srcX, srcY)<<endl;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--)
		solve();
}
