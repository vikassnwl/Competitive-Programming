class Solution {
    
    int timer = 0;
    vector<vector<int>> ans;
    
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
                low[node] = min(low[node], low[child]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[n];
        for(vector<int> conn: connections){
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        int vis[n], in[n], low[n];
        memset(vis, 0, sizeof vis);
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(i, -1, graph, vis, in, low);
        }
        return ans;
    }
};
