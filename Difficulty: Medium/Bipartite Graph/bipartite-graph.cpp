class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        // Step 1: Create adjacency list
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(V,-1);
        queue<int>q;
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<adj[node].size();j++){
                        //color is not assign to them 
                        if(color[adj[node][j]]==-1){
                            color[adj[node][j]]=(color[node]+1)%2;
                            q.push(adj[node][j]);
                        }
                        else{
                            //color already assigned ho 
                            if(color[node]==color[adj[node][j]])
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;  //means it is a bipertite graph 
        
    }
};