#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n-1);
    for(int i=0; i<n-1; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }

    

    return 0;
}