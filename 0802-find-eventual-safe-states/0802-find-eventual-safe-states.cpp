class Solution {
public:

    bool DFS(int node, vector<bool>& path, vector<bool>& visited, vector<vector<int>>& graph){
        visited[node] = 1;
        path[node] = 1;

        // travel to eah neigh
        for(int neigh: graph[node]){
            
            // found the cycle
            if(path[neigh] == 1)    return true;

            // already visited
            if(visited[neigh] == 1) continue;

            if(DFS(neigh, path, visited, graph))    return true;
        }

        path[node] = 0;
        return false;
    }



    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> path(n,0);
        vector<bool> visited(n,0);
        
        for(int i=0; i<n; i++){
            if(!visited[i]) DFS(i, path, visited, graph);
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(path[i] == false)    ans.push_back(i);
        }

        return ans;
    }
};