class Solution {
public:
    vector<vector<int>> adj;
    vector<int> sz;
    vector<int> ans;
    void dfs1(int node, int parent, int depth) {
        ans[0] += depth;
        sz[node] = 1;
        for (int nei : adj[node]) {
            if (nei == parent) continue;
            dfs1(nei, node, depth + 1);
            sz[node] += sz[nei];
        }
    }
    void dfs2(int node,int parent,int n){
        for(int nei:adj[node]){
            if(nei==parent) continue;
            ans[nei]=ans[node]+n-2*sz[nei];
            dfs2(nei,node,n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        sz.resize(n);
        ans.resize(n,0);
        for(auto edge:edges){
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }
        dfs1(0,-1,0);
        dfs2(0,-1,n);
        return ans;
    }
};