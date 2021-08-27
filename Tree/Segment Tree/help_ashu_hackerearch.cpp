#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;
 
int ar[100000];
int st[400000];
 
int sum(int a, int b){
	return a+b;
}
 
void update(int si, int ss, int se, int qi){
	if(ss==se){
		st[si] = ar[ss]%2==0?1:0;
		return;
	}
	int mid = (ss+se)/2;
	if(qi<=mid)
		update(2*si, ss, mid, qi);
	else update(2*si+1, mid+1, se, qi);
 
	st[si] = sum(st[2*si], st[2*si+1]);
}
 
void buildTree(int si, int ss, int se){
	if(ss==se){
		st[si] = ar[ss]%2==0?1:0;
		return;
	}
	int mid = (ss+se)/2;
	buildTree(2*si, ss, mid);
	buildTree(2*si+1, mid+1, se);
 
	st[si] = sum(st[2*si], st[2*si+1]);
}
 
int query(int si, int ss, int se, int qs, int qe){
	if(ss>qe or se<qs) return 0;
	if(ss>=qs and se<=qe) return st[si];
	int mid = (ss+se)/2;
	
	return sum(query(2*si, ss, mid, qs, qe), query(2*si+1, mid+1, se, qs, qe));
}
 
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>ar[i];
	buildTree(1, 0, n-1);
	int q;
	cin>>q;
	while(q--){
		int type, l, r;
		cin>>type>>l>>r;
		l--, r--;
		if(type==0){
			r++;
			if(ar[l]%2!=r%2){
				ar[l] = r;
				update(1, 0, n-1, l);
			}
		}
		else if(type==1){
			cout<<query(1, 0, n-1, l, r)<<endl;
		}
		else{
			int total = r-l+1;
			cout<<total-query(1, 0, n-1, l, r)<<endl;
		}
	}
}
