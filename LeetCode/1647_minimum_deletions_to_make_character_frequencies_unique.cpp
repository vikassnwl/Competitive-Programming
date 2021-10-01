class Solution {
public:
    int minDeletions(string s) {
        int arr[26]{};
        for(char c: s) arr[(int)c-97]++;
        sort(arr, arr+26, greater<int>());
        int ans = 0;
        for(int i=0; i<25; i++){
            if(arr[i]<=arr[i+1]){
                int x = min(arr[i+1]-arr[i]+1, arr[i+1]);
                ans += x;
                arr[i+1] -= x;
            }
        }
        return ans;
    }
};
