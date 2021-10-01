#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2, n3; cin>>n1>>n2>>n3;
    int arr1[n1], arr2[n2], arr3[n3];
    for(int i=0; i<n1; i++) cin>>arr1[i];
    for(int i=0; i<n2; i++) cin>>arr2[i];
    for(int i=0; i<n3; i++) cin>>arr3[i];
    
    stack<int> st1, st2, st3;
    st1.push(0), st2.push(0), st3.push(0);

    for(int i=n1-1; i>=0; i--){
        st1.push(st1.top()+arr1[i]);
    }
    
    for(int i=n2-1; i>=0; i--){
        st2.push(st2.top()+arr2[i]);
    }
    
    for(int i=n3-1; i>=0; i--){
        st3.push(st3.top()+arr3[i]);
    }
    
    while(st1.top()!=st2.top()||st2.top()!=st3.top()){
        if(st1.top()>=st2.top() and st2.top()>=st3.top()) st1.pop();
        else if(st2.top()>=st1.top() and st2.top()>=st3.top()) st2.pop();
        else st3.pop();
    }
    cout<<st1.top();
}
