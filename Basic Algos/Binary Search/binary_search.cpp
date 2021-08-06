#include<bits/stdc++.h>
using namespace std;

int main(){	
	//binary search
	vector<int> v{2, 3, 5, 7, 9}; //sequence should be sorted
	for(int x: v){
		cout<<x<<" ";
	}
	cout<<endl;
	int find;
	cin>>find;
	int l = 0;
	int u = v.size()-1;
	bool flag = true;
	while(l<=u){
		int mid = (l+u)/2;
		if(v[mid] == find){
			cout<<"Item found at index "<<mid<<endl;
			flag = false;
			break;
		}
		if(v[mid] > find){
			u = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	if(flag){
		cout<<"Item not found!"<<endl;
	}
}


