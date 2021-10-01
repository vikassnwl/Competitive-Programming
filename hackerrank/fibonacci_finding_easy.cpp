#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

//================PBDS==================
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset =
tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
//======================================

void mul(int A[][2], int B[][2]){
    ll res[2][2];
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            res[i][j] = 0;
            for(int k=0; k<2; k++){
                res[i][j] += 1ll*A[i][k]*B[k][j];
                res[i][j] %= mod;
            }
        }
    }
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            A[i][j] = res[i][j];
}

void solve(){
    int t;
    cin>>t;
    while(t--){
        int a, b, p;
        cin>>a>>b>>p;

        int M[2][2]{{0, 1}, {1, 1}}, I[2][2]{{1, 0}, {0, 1}};

        while(p){
            if(p%2){
                p--;
                mul(I, M);
            }
            else{
                p /= 2;
                mul(M, M);
            }
        }
        cout<<(1ll*a*I[0][0]+1ll*b*I[1][0])%mod<<endl;
    }
}

int main(){    
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
