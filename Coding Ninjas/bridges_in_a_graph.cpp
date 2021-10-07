
vector<vector<int>> ans;
int timer = 0;

void dfs(int node, int par, vector<int>* graph, int* vis, int* in, int* low){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    for(int child: graph[node]){
        if(child==par) continue;
        if(!vis[child]){
            dfs(child, node, graph, vis, in, low);
            if(low[child]>in[node])
                ans.push_back({child, node});
            low[node] = min(low[node], low[child]);
        }
        else{
            low[node] = min(low[node], in[child]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    vector<int> graph[v];
    for(vector<int> edge: edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    int vis[v], in[v], low[v];
    for(int i=0; i<v; i++) vis[i] = 0;
//     memset(vis, 0, sizeof vis);
    ans.clear();
    for(int i=0; i<v; i++){
        if(!vis[i])
            dfs(i, -1, graph, vis, in, low);
    }
    return ans;
}
