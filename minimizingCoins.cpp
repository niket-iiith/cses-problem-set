#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        c[i] = temp;
    }

    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i-c[j] >= 0 && dp[i-c[j]] != INT_MAX)
                dp[i] = min(dp[i], dp[i-c[j]]+1);
        }
    }

    if(dp[x] != INT_MAX)
        cout << dp[x];
    else
        cout << "-1";

    return 0;
}