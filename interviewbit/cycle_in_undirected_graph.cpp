bool contains_cycle(int node, int par, int* vis, vector<int>* tree){
    vis[node] = 1;
    for(int child: tree[node]){
        if(!vis[child]){
            if(contains_cycle(child, node, vis, tree))
                return true;
        }
        else{
            if(child!=par)
                return true;
        }
    }
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> tree[A+1];
    int vis[A+1];
    memset(vis, 0, sizeof vis);
    for(vector<int> v: B){
        int a = v[0], b = v[1];
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int i=1; i<=A; i++){
        if(!vis[i]){
            if(contains_cycle(i, -1, vis, tree))
                return 1;
        }
    }
    return 0;
}
