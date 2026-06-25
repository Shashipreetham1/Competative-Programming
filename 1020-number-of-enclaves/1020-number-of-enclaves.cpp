class Solution {
public:
    int m , n;
    void walk(vector<vector<int>>& grid , int r , int c){
        if(r < 0 || r > m-1 || c < 0 || c > n-1) return;
        if(!grid[r][c]) return;
        grid[r][c]=0;
        walk(grid , r , c+1);
        walk(grid , r+1 , c);
        walk(grid , r , c-1);
        walk(grid , r-1 , c);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size() ; n= grid[0].size();
        for(int i=0 ; i < m ; i++){
            walk(grid , i , 0);
            walk(grid , i , n-1);
        }
        for(int i=0 ; i <n ; i++){
            walk(grid ,  0, i);
            walk(grid , m-1 , i);
        }
        int ans = 0;
        for(auto r : grid){
            for(int a : r){
                if(a==1) ans++;
            }
        }

        return ans;
    }
};