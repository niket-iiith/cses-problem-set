#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        c[i] = temp;
    }

    vector<int> dp(x+1, 0);
    dp[0] = 1;
    int mod = 1e9+7;

    for(int i=0; i<n; i++) {
        for(int j=c[i]; j<=x; j++) {
            dp[j] = (dp[j] + dp[j-c[i]]) % mod;
        }
    }

    cout << dp[x];

    return 0;
}