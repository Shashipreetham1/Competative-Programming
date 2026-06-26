class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int z=0;
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        int time=1;
        queue<pair<int,int>> q;
        vector<vector<int>> out(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) q.push({i,j});
                else z++;
            }
        }
        while(!q.empty() && z>0){
            int sz=q.size();
            while(sz--){
                auto cell=q.front();
                q.pop();
                int i=cell.first;
                int j=cell.second;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if((nr>=0 && nc>=0 && nr<n && nc<m) && mat[nr][nc]==1){
                        mat[nr][nc]=0;
                        z--;
                        q.push({nr,nc});
                        out[nr][nc]=time;
                    }
                }
            }
            time++;
        }
        return out;
    }
};