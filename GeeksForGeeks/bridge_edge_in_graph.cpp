class Solution
{
    
    int timer = 0;
    int ans = 0;
    
    void dfs(int node, int par, vector<int>* graph, int* vis, int* in, int c, int d){
        vis[node] = 1;
        in[node] = timer++;
        for(int child: graph[node]){
            if(child==par) continue;
            if(!vis[child]){
                dfs(child, node, graph, vis, in, c, d);
                if(in[child]>in[node]){
                    if(child==c and node==d or child==d and node==c)
                        ans = 1;
                }
                else{
                    in[node] = in[child];
                }
            }
            else{
                in[node] = min(in[node], in[child]);
            }
        }
    }
    
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int vis[V], in[V];
        memset(vis, 0, sizeof vis);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, in, c, d);
            }
        }
        return ans;
    }
};
