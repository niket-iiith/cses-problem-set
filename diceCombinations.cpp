#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    int mod = 1e9+7;
    cin >> n;

    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    if(n < 4) {
        cout << dp[n];
        return 0;
    }

    for(int i=4; i<=n; i++) {
        for(int j=1; j<=6; j++) {
            if(i-j >= 0)
                dp[i] = (dp[i] + dp[i-j])%mod;
        }
    }

    cout << dp[n];

    return 0;
}