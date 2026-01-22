#include <bits/stdc++.h>
using namespace std;

bool valid(int row, int col, int m, int n) {
    return (row >= 0 && row < m && col >= 0 && col < n);
}

void dfs(int row, int col, int& cnt, vector<vector<int>>& grid, vector<vector<int>>& vis,
         vector<pair<int,int>>& path, vector<vector<pair<int,int>>>& paths, int m, int n) {
    if(row == m-1 && col == n-1) {
        cnt++;
        path.push_back({row,col});
        paths.push_back(path);
        path.pop_back();
        return;
    }

    vis[row][col] = 1;
    path.push_back({row,col});

    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,-1,0,1};

    for(int i=0;i<4;i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(valid(nrow,ncol,m,n) && !vis[nrow][ncol] && grid[nrow][ncol]==0) {
            dfs(nrow,ncol,cnt,grid,vis,path,paths,m,n);
        }
    }

    path.pop_back();
    vis[row][col] = 0;
}

int main() {
    int m,n;
    cout << "Enter grid size (m n): ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n,0));
    cout << "Enter blocked cells count: ";
    int b; cin >> b;
    cout << "Enter blocked cell positions (row col):\n";
    for(int i=0;i<b;i++) {
        int r,c; cin >> r >> c;
        if(valid(r,c,m,n)) grid[r][c] = 1;
    }

    vector<vector<int>> vis(m, vector<int>(n,0));
    int cnt=0;
    vector<vector<pair<int,int>>> paths;
    vector<pair<int,int>> path;

    if(grid[0][0]==0 && grid[m-1][n-1]==0)
        dfs(0,0,cnt,grid,vis,path,paths,m,n);

    cout << "Total paths found: " << cnt << "\n";

    if(paths.empty()) {
        cout << "No path exists.\n";
        return 0;
    }

    // Group by length
    map<int, vector<vector<pair<int,int>>>> grouped;
    for(auto &p : paths) {
        int len = p.size();
        grouped[len].push_back(p);
    }

    // Smallest length group is at begin()
    auto it = grouped.begin();
    cout << "Smallest paths with length " << it->first << ":\n";
    int idx = 1;
    for(auto &p : it->second) {
        cout << "  Path " << idx++ << ": ";
        for(auto &coord : p) cout << "(" << coord.first << "," << coord.second << ") ";
        cout << "\n";
    }

    return 0;
}