class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<int>& vis){
        vis[i]=1;
        for(auto n:adj[i]){
            if(!vis[n]){
                dfs(n,adj,vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<vector<int>> adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(V,0);
        int count=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};