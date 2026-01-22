#include <bits/stdc++.h>
using namespace std;
bool valid(int row, int col, int m, int n)
{
    if(row>=0 && row<m && col>=0 && col<n) return true;
    return false;
}
void func(int row, int col, int& cnt, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>& path, vector<vector<pair<int,int>>>& paths)
{
    if(row == 9 && col == 9) {
        cnt++;
        path.push_back({row,col});
        paths.push_back(path); 
        path.pop_back();
        return;
    }

    int m=grid.size();
    int n=grid[0].size();
    vis[row][col]=1;
    path.push_back({row,col});
    int delrow[]={-1,0,1,0};
    int delcol[]={0,-1,0,1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(valid(nrow,ncol,m,n) && !vis[nrow][ncol] && grid[nrow][ncol]==0)
        {
            func(nrow,ncol,cnt,grid,vis,path,paths);
        }
    }
    path.pop_back();    
    vis[row][col]=0;
}
int main()
{
    vector<vector<int>> grid={
        {0,1,0,0,0,1,0,0,1,0},
        {0,0,0,1,0,0,0,1,0,0},
        {1,0,1,0,0,1,0,0,0,1},
        {0,0,0,0,1,0,1,0,0,0},
        {0,1,0,0,0,1,0,1,0,0},
        {0,0,1,0,1,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,1,0},
        {0,0,1,0,0,0,1,0,0,0},
        {0,1,0,0,1,0,0,0,0,0},
        {0,0,0,1,0,0,0,1,1,0}
    };
    vector<vector<int>> vis(10,vector<int>(10,0));
    int cnt=0;
    vector<vector<pair<int,int>>> paths;
    vector<pair<int,int>> path;
    func(0,0,cnt,grid,vis,path, paths);
    cout<<cnt;
    for(int i=0;i<paths.size();i++)
    {
        cout<<"\nPath no "<<i<<": "<<endl;
        for(int j=0;j<paths[i].size();j++)
        {
            cout<<"("<<paths[i][j].first<<","<<paths[i][j].second<<")   ";
        }
    }
    return 0;
}