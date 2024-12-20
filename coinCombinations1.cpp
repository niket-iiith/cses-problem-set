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

    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i - c[j] >= 0) {
                dp[i] = ( dp[i] + dp[i-c[j]] ) % mod;
            }
        }
    }

    cout << dp[x];

    return 0;
}