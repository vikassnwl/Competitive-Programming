#include<bits/stdc++.h>
using namespace std;

//================PBDS==================
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset =
tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
//======================================

#define endl '\n'
#define mod 1000000007
#define int long long

struct Point{
	int x, y;
};

int orientation(Point p1, Point p2, Point p3){
	int val = (p2.y-p1.y)*(p3.x-p2.x)-(p2.x-p1.x)*(p3.y-p2.y);
	if(val==0) return 0;
	return (val>0)?1:2;
}

void solve(){
	Point p1 = {1, 4}, p2 = {2, 5}, p3 = {3, 6};
	int o = orientation(p1, p2, p3);
	if(o==0) cout<<"Linear";
	else if(o==1) cout<<"Clockwise";
	else cout<<"CounterClockwise";
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
