#include<bits/stdc++.h>
using namespace std;

int main() {
    int m , n;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);

    // take input and create adj list
    for(int i=0; i<m; i++) {
        int src, dst, prc;
        cin >> src >> dst >> prc;
        adj[src].push_back({dst, prc});
    }

    // make dijkstra's array : dist[price][couponUsed]  ;  { 0: not used }
    vector<vector<long long>> dist(n+1, vector<long long>(2, 1e15));
    dist[1][0] = 0;  // start at city 1 , coupon not used

    // pq { price , src , couponUsed } 
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.push({0, 1, 0}); // coupon not used
    while(!pq.empty()) {
        auto [prc, u, used] = pq.top();
        pq.pop();

        if(prc > dist[u][used]) continue;
        
        for(auto [v, w] : adj[u]) {
            // traverse normally
            if(prc + w < dist[v][used]) {
                dist[v][used] = prc + w;
                pq.push({dist[v][used], v, used});
            }
            
            if(!used && prc+w/2 < dist[v][1]) {
                dist[v][1] = prc + w/2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }
    
    cout << min(dist[n][0], dist[n][1]);

}