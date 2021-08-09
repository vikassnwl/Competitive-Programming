    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        vector<pair<long long,long long>>vp;
        for(int i=0;i<N;i++)
        {
            vp.push_back({B[i], A[i]});
        }
        sort(vp.rbegin(),vp.rend());
        int i=0;
        long long  ans=0;
        while(T)
        {
            if(vp[i].second<=T)
            {
                T-=vp[i].second;
                ans+=(vp[i].first*vp[i].second);
                i++;
            }
            else{
                ans+=T*vp[i].first;
                i++;
                T=0;
            }
        }
        return ans;
    }
