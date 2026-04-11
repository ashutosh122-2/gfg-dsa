class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path) {
        visited[node] = 1;
        path[node] = 1;

        for(int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];

            if(visited[neighbor] == 0) {
                if(dfs(neighbor, adj, visited, path)) {
                    return true;
                }
            }
            else if(path[neighbor] == 1) {
                return true; // cycle found
            }
        }

        path[node] = 0; // remove from current path
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {

        // Step 1: create adjacency list
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        // Step 2: visited + path arrays
        vector<int> visited(V, 0);
        vector<int> path(V, 0);

        // Step 3: check all nodes
        for(int i = 0; i < V; i++) {
            if(visited[i] == 0) {
                if(dfs(i, adj, visited, path)) {
                    return true;
                }
            }
        }

        return false;
    }
};