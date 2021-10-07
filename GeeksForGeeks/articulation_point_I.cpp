class Solution {
    
int timer = 0;
set<int> res;

void dfs(int node, int par, vector<int>* graph, int* vis, int* in, int* low){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    int children = 0;
    for(int child: graph[node]){
        if(child==par) continue;
        if(!vis[child]){
            dfs(child, node, graph, vis, in, low);
            if(low[child]>=in[node] and par!=-1)
                res.insert(node);
            low[node] = min(low[node], low[child]);
            children++;
        }
        else{
            low[node] = min(low[node], in[child]);
        }
    }
    if(par==-1 and children>1)
        res.insert(node);
}
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int vis[V], in[V], low[V];
        memset(vis, 0, sizeof vis);
        for(int i=0; i<V; i++){
            if(!vis[i])
                dfs(i, -1, adj, vis, in, low);
        }
        if(res.size()){
            vector<int> v;
            for(int x: res) v.push_back(x);
            return v;
        }
        return {-1};
    }
};
