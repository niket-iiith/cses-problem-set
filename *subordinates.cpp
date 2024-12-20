#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int>& sub) {
    for(auto child : adj[node]) {
        dfs(child, adj, sub);
        sub[node] = sub[child] + 1;
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> boss(n-1);
    for(int i=0; i<n-1; i++) {
        cin >> boss[i];
    }

    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++) {
        adj[boss[i]].push_back(i+2);
    }

    vector<int> sub(n+1);
    dfs(1, adj, sub);

    for(int i=1; i<=n; i++)
        cout << sub[i] << " ";

    return 0;
}