#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    if(grid[0][0] == '*') {
        cout << "0";
        return 0;
    }

    for(int i=1; i<n; i++) {
        if(grid[i][0] == '*' && i!=n-1) {
            grid[i+1][0] = '*';
        }
        if(grid[0][i] == '*' && i!=n-1){
            grid[0][i+1] = '*';
        }
    }

    vector<vector<long int>> dp(n, vector<long int>(n));
    for(int i=0; i<n; i++){
        if(grid[i][0] != '*') 
            dp[i][0] = 1;
        else 
            dp[i][0] = 0;

        if(grid[0][i] != '*') 
            dp[0][i] = 1;
        else 
            dp[0][i] = 0;
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            if(grid[i][j] == '*')
                dp[i][j] = 0;
            else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
    }

    cout << dp[n-1][n-1];

    return 0;
}