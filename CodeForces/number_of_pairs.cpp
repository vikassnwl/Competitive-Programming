// video tutorial  -> /mnt/B238844C38841191/Ubuntu Stuff/Competitive Programming

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
			auto itr1 = lower_bound(v.begin()+i+1, v.end(), l-v[i]);
			auto itr2 = upper_bound(v.begin()+i+1, v.end(), r-v[i]);
			ans += itr2-itr1;
		}
		cout<<ans<<endl;
	}
}

