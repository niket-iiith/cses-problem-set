#include<bits/stdc++.h>
using namespace std;

void dfs(int index, vector<int> &count, vector<vector<int>> &sub) {
    for(auto child : sub[index]) {
        dfs(child, count, sub);
        //cout << "index = " << index << ", child = " << child << endl;
        count[index] += count[child] + 1;
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> boss(n-1);
    for(int i=0; i<n-1; i++) {
        cin >> boss[i];
    }

    vector<vector<int>> sub(n+1);
    for(int i=0; i<n-1; i++) {
        sub[boss[i]].push_back(i+2);
    }

    vector<int> count(n+1, 0);
    dfs(1, count, sub);

    // test
    // for(int i=0; i<n-1; i++) {
    //     for(auto child : sub[i]) {
    //         cout << child << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i=1; i<n+1; i++)
        cout << count[i] << " ";

    return 0;
}