#include <bits/stdc++.h>
using namespace std;
bool valid(int row, int col, int m, int n)
{
    if(row>=0 && row<m && col>=0 && col<n) return true;
    return false;
}
void func(int row, int col, int &cnt, vector<vector<int>>& grid, vector<vector<int>>& vis)
{
    if(row==9 && col==9) {cnt++;return;}
    int m=grid.size();
    int n=grid[0].size();
    vis[row][col]=1;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,-1,0,1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(valid(nrow,ncol,m,n) && !vis[nrow][ncol] && grid[nrow][ncol]==0)
        {
            func(nrow,ncol,cnt,grid,vis);
        }
    }
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
    func(0,0,cnt,grid,vis);
    cout<<cnt;
    return 0;
}