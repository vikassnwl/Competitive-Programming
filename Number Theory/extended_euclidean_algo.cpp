#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int gcd(int a, int b, int &x, int &y){
	if(b==0){
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1-y1*(a/b);
	return d;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x = 1;
	int y = 0;
	gcd(57, 81, x, y);
	cout<<x<<" "<<y;
}
