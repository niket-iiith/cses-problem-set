#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& building, vector<vector<bool>>& vis, int i, int j, int n, int m) {
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || !building[i][j])
        return;
    
    vis[i][j] = true;

    dfs(building, vis, i+1, j, n, m);
    dfs(building, vis, i-1, j, n, m);
    dfs(building, vis, i, j+1, n, m);
    dfs(building, vis, i, j-1, n, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> building(n, vector<int>(m));
    char temp;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> temp;
            if(temp == '#') building[i][j] = 0;
            else building[i][j] = 1;
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int rooms = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j] && building[i][j]==1){
                dfs(building, vis, i, j, n, m);
                rooms++;
            }
        }
    }

    cout << rooms;

    return 0;
}