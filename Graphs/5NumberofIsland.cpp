
#include<iostream>
#include<vector>

bool canMove(int x,int y,vector<vector<bool>> &visited){
    return (x>=0 && x< visited.size()) && (y>=0 && y< visited[0].size()) &&  !visited[x][y];
}
void DFS(int x,int y,vector<vector<char>>& grid,vector<vector<bool>> &visited){
    visited[x][y] = true;
    vector<pair<int,int>> directions = {{0,-1},{0,1},{1,0},{-1,0}}; // can move in 4 directions
    for(auto &dirs:directions){
    if( canMove(x+dirs.first,y+dirs.second,visited) && grid[x+dirs.first][y+dirs.second]=='1') DFS(x+dirs.first,y+dirs.second,grid,visited);
    } 
}
int numIslands(vector<vector<char>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),0));
    int island = 0;
    for(int i = 0; i<grid.size();i++){
        for(int j = 0; j<grid[0].size();j++){
            if ( grid[i][j] == '1' && !visited[i][j]){
                DFS(i,j,grid,visited);
                island++;
            }
        }
    }
    return island;
}