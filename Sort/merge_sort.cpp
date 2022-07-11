#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int temp[100];

void merge_sort(int l, int r, int* arr){
	if(l<r){
		int mid = (l+r)/2;
		merge_sort(l, mid, arr);
		merge_sort(mid+1, r, arr);
		int i = l, j = mid+1, k=l;
		while(i<=mid and j<=r){
			if(arr[i]<arr[j]){
				temp[k] = arr[i];
				i++;
			}
			else{
				temp[k] = arr[j];
				j++;
			}
			k++;
		}
		while(i<=mid){
			temp[k] = arr[i];
			i++;
			k++;
		}
		while(j<=r){
			temp[k] = arr[j];
			j++;
			k++;
		}
		for(int i=l; i<k; i++){
			arr[i] = temp[i];
		}
	}
}

void solve(){
	int n; cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int l = 0, r = n-1;
	merge_sort(l, r, arr);
	for(int x: arr) cout<<x<<" ";
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
}
