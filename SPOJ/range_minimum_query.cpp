//Solution 1: Brute Force, Time: 1.11
#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;
 
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	int q;
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		int ans = INT_MAX;
		for(int i=l; i<=r; i++){
			ans = min(ans, v[i]);
		}
		cout<<ans<<endl;
	}
}

//Solution 2: Segment Tree, Time: 0.08
#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

int ar[100001], st[400004];

void build(int si, int ss, int se){
	if(ss==se){
		st[si] = ar[ss];
		return;
	}
	int mid = (ss+se)/2;
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);

	st[si] = min(st[2*si], st[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe){
	if(ss>qe or se<qs) return INT_MAX;
	if(ss>=qs and se<=qe) return st[si];
	int mid = (ss+se)/2;
	return min(query(2*si, ss, mid, qs, qe), query(2*si+1, mid+1, se, qs, qe));
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q, l, r;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>ar[i];

	build(1, 1, n);
	cin>>q;

	while(q--){
		cin>>l>>r;
		cout<<query(1, 1, n, l+1, r+1)<<endl;
	}
}

//Solution 3: SQRT Decomposition, Time: 0.08
#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;
 
const int blk_size = 1000;
 
vector<int> res(1000);
 
void process(vector<int> &v){
	int idx = 0;
	for(int i=0; i<=1e5; i+=blk_size){
		int min_ = INT_MAX;
		for(int j=i; j<i+blk_size; j++){
			min_ = min(min_, v[j]);
		}
		res[idx] = min_;
		idx++;
	}
}
 
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin>>n;
	vector<int> v(1e5+1001);
	for(int i=1; i<=n; i++){
		cin>>v[i];
	}
	process(v);
 
	int q;
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		l++, r++;
		int min_ = INT_MAX;
		if(l/blk_size==r/blk_size){
			for(int i=l; i<=r; i++){
				min_ = min(min_, v[i]);
			}
		}
		else{
		for(int i=l; i<((l/blk_size)+1)*blk_size; i++){
			min_ = min(min_, v[i]);
		}
		for(int i=l/blk_size+1; i<=r/blk_size-1; i++){
			min_ = min(min_, res[i]);
		}
		for(int i=(r/blk_size)*blk_size; i<=r; i++){
			min_ = min(min_, v[i]);
		}
		}
		cout<<min_<<endl;
	}
}
