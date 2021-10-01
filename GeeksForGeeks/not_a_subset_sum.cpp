class Solution{   
public:
    long long findSmallest(long long arr[], int n) {
        long long x = 1;
        for(int i=0; i<n; i++){
            if(arr[i]<=x) x += arr[i];
            else break;
        }
        return x;
    }
};
