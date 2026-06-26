class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                vis[0][j]=1;
                q.push({0,j});
            }
            if(board[n-1][j]=='O'){
                vis[n-1][j]=1;
                q.push({n-1,j});
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                vis[i][0]=1;
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while(!q.empty()){
            auto cell=q.front();
            q.pop();
            int i=cell.first;
            int j=cell.second;
            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if((nr>=0 && nc>=0 && nr<n && nc<m) && board[nr][nc]=='O' && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};