#include<bits/stdc++.h>
using namespace std;
#define N 50
#define mod 1000000007

int mat[N][N], I[N][N];

void mul(int I[][N], int mat[][N], int dim){
	long long res[dim][dim];
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			res[i][j] = 0;
			for(int k=0; k<dim; k++){
				res[i][j] += (long long)I[i][k]*mat[k][j];
				res[i][j] %= mod;
			}
		}
	}
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			I[i][j] = res[i][j];
		}
	}
}

int main(){	
	int tc;
	cin>>tc;
	while(tc--){
		int dim, p;
		cin>>dim>>p;
		for(int i=0; i<dim; i++){
			for(int j=0; j<dim; j++){
				cin>>mat[i][j];
			}
		}
		for(int i=0; i<dim; i++){
			for(int j=0; j<dim; j++){
				if(i==j){
					I[i][j] = 1;
				}
				else{
					I[i][j] = 0;
				}
			}
		}
		//for(int i=0; i<p; i++){
		//	mul(mat, dim, p);
		//}
		while(p){
			if(p%2){
				p--;
				mul(I, mat, dim);
			}
			else{
				p /= 2;
				mul(mat, mat, dim);
			}
		}
		for(int i=0; i<dim; i++){
			for(int j=0; j<dim; j++){
				cout<<I[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}


