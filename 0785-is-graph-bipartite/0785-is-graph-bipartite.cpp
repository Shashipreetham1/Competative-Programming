class Solution {
public:
    bool bfs(int i,vector<vector<int>>& graph,vector<int>& col){
        queue<int> q;
        q.push(i);
        col[i]=0;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(int it:graph[n]){
                if(col[it]==-1){
                    col[it]=!col[n];
                    q.push(it);
                }
                else if(col[it]==col[n]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!bfs(i,graph,col)){
                    return false;
                }
            }
        }
        return true;
    }
};