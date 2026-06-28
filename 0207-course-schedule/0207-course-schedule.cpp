class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<int>& vis,vector<int>& path){
        vis[i]=1;
        path[i]=1;
        for(int n:adj[i]){
            if(!vis[n]){
                if( dfs(n,adj,vis,path)) return true;
            }
            else if(path[n]) return true;
        }
        path[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return false;
            }
        }
        return true;
    }
};