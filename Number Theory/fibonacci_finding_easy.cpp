// Solution 1(My):

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

void mul(vector<vector<int>> &A, vector<vector<int>> &B, int row)
{
    vector<vector<long long>> res(row, vector<long long>(2, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                res[i][j] += (long long)A[i][k] * B[k][j];
                res[i][j] %= mod;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            A[i][j] = res[i][j];
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        if (n == 0)
        {
            cout << a << endl;
        }
        else
        {
            vector<vector<int>> magic_mat(2, vector<int>(2, 1));
            magic_mat[0][0] = 0;
            vector<vector<int>> I(2, vector<int>(2, 0));
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (i == j)
                    {
                        I[i][j] = 1;
                    }
                }
            }
            vector<vector<int>> A{{a, b}};
            // for(int i=0; i<n; i++){
            //     mul(I, magic_mat, 2);
            // }
            while (n)
            {
                if (n % 2)
                {
                    n--;
                    mul(I, magic_mat, 2);
                }
                else
                {
                    n /= 2;
                    mul(magic_mat, magic_mat, 2);
                }
            }
            mul(A, I, 1);
            cout << A[0][0] << endl;
        }
    }
}


// Solution 2(CodeNCode):

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007

lli ar[3];
lli I[3][3], T[3][3];

void mul(lli A[3][3], lli B[3][3], int dim){
    lli res[dim+1][dim+1];
    for(int i=1; i<=dim; i++){
        for(int j=1; j<=dim; j++){
            res[i][j] = 0;
            for(int k=1; k<=dim; k++){
                res[i][j] += A[i][k]*B[k][j];
                res[i][j] %= mod;
            }
        }
    }
    for(int i=1; i<=dim; i++){
        for(int j=1; j<=dim; j++){
            A[i][j] = res[i][j];
        }
    }
}

lli getFib(int n){
    if(n<=2) return ar[n];
    
    I[1][1] = I[2][2] = 1;
    I[1][2] = I[2][1] = 0;

    T[1][1] = 0;
    T[1][2] = T[2][1] = T[2][2] = 1;

    n--;
    while(n){
        if(n%2)
            mul(I, T, 2), n--;
        else
            mul(T, T, 2), n /= 2;
    }
    lli Fn = (ar[1]*I[1][1]+ar[2]*I[2][1])%mod;
    return Fn;
}

int main(){    
    int t, n;
    cin>>t;
    while(t--){
        cin>>ar[1]>>ar[2]>>n, n++;
        cout<<getFib(n)<<endl;
    }
}
