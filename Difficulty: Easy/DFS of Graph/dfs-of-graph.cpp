class Solution {
public:
    void DFS(int node, vector<vector<int>>& adj, vector<int>& ans, vector<int>& visited) {
        visited[node] = 1;
        ans.push_back(node);

        for(int j = 0; j < adj[node].size(); j++) {
            if(!visited[adj[node][j]]) {
                DFS(adj[node][j], adj, ans, visited);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int v = adj.size();   // ✅ FIXED

        vector<int> visited(v, 0);  // ✅ type fixed
        vector<int> ans;

        DFS(0, adj, ans, visited); // start from 0

        return ans;
    }
};