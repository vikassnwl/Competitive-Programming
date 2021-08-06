// video tutorial  -> /mnt/B238844C38841191/Ubuntu Stuff/Competitive Programming

// Solution 1: using built-in lower_bound and upper_bound functions
#include<bits/stdc++.h>
using namespace std;

int main(){	
	int tc;
	cin>>tc;
	while(tc--){
		int n, l, r;
		cin>>n>>l>>r;
		vector<int> v(n);
		for(int i=0; i<n; i++){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		long long ans = 0;
		for(int i=0; i<n; i++){
			auto itr1 = lower_bound(v.begin()+i+1, v.end(), l-v[i]); // uses binary search
			auto itr2 = upper_bound(v.begin()+i+1, v.end(), r-v[i]);
			ans += itr2-itr1;
		}
		cout<<ans<<endl;
	}
}


// Solution 2: (implemented from scratch using binary search)
#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &v, int i, int find){	
	int l = i+1;
	int u = v.size()-1;
	int lb = -1;
	while(l<=u){
		int mid=(l+u)/2;
		if(v[mid]==find){
			lb = mid;
			u = mid-1;
			continue;
		}
		if(v[mid]<find){
			l = mid+1;
		}
		else{
			u = mid-1;
		}
	}
	if(lb==-1){
		lb = l;
	}
	return lb;
}

int upper_bound(vector<int> &v, int i, int find){	
	int l = i+1;
	int u = v.size()-1;
	int ub = -1;
	while(l<=u){
		int mid=(l+u)/2;
		if(v[mid]==find){
			ub = mid;
			l = mid+1;
			continue;
		}
		if(v[mid]<find){
			l = mid+1;
		}
		else{
			u = mid-1;
		}
	}
	if(ub==-1){
		ub = u;
	}
	return ub+1;
}

int main(){	
	int tc;
	cin>>tc;
	while(tc--){
		int n, l, r;
		cin>>n>>l>>r;
		vector<int> v(n);
		for(int i=0; i<n; i++){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		long long ans = 0;
		for(int i=0; i<n; i++){
			ans += upper_bound(v, i, r-v[i])-lower_bound(v, i, l-v[i]);
		}
		cout<<ans<<endl;
	}
}
