class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st) {
        visited[node] = 1;

        for(int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];

            if(visited[neighbor] == 0) {
                dfs(neighbor, adj, visited, st);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        // Step 1: Create adjacency list
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        // Step 2: visited array
        vector<int> visited(V, 0);

        // Step 3: stack
        stack<int> st;

        // Step 4: run DFS for all nodes
        for(int i = 0; i < V; i++) {
            if(visited[i] == 0) {
                dfs(i, adj, visited, st);
            }
        }

        // Step 5: store result
        vector<int> ans;
        while(st.size() > 0) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};