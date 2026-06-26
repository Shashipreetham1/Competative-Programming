class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        int time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        while(!q.empty() && fresh>0){
            int sz=q.size();
            while(sz--){
                auto cell=q.front();
                q.pop();
                int i=cell.first;
                int j=cell.second;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if((nr>=0 && nc>=0 && nr<n && nc<m) && grid[nr][nc]==1){
                        fresh--;
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
            time++;
        }
        if(fresh!=0) return -1;
        return time;
    }
};