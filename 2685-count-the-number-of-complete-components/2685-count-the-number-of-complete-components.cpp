class Solution {
public:
    bool bfs(int i,vector<vector<int>>& adj,vector<int>& vis){
        queue<int> q;
        q.push(i);
        vis[i]=1;
        int ver=0,edge=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ver++;
            for(int it:adj[node]){   
                edge++;
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        edge /= 2;
        return edge == (ver * (ver - 1)) / 2;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(bfs(i,adj,vis))
                cnt++;
            }
        }
        return cnt;
    }
};