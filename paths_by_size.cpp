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
    map<int, vector<vector<pair<int,int>>>> grouped;
    for(auto &p : paths) {
        int len = p.size();
        grouped[len].push_back(p);
    }
    for(auto &entry: grouped)
    {
        int n=entry.first;
        cout << "Paths with length " << n << ":\n";
        int idx = 1;
        for(auto &p : entry.second) {
            cout << "  Path " << idx++ << ": ";
            for(auto &coord : p) cout << "(" << coord.first << "," << coord.second << ") ";
            cout << "\n";
        }
        cout << "\n";
    }
    auto it=grouped.begin();
    int idx = 1;
    cout<<"Smallest paths with length "<<it->first<<": \n";
    for(auto &p : it->second) {
        cout << "  Path " << idx++ << ": ";
        for(auto &coord : p) cout << "(" << coord.first << "," << coord.second << ") ";
        cout << "\n";
    }

    return 0;
}