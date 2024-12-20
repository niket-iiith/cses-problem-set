#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);
    for(int i=0; i<n; i++) cin >> price[i];
    for(int i=0; i<n; i++) cin >> pages[i];

    vector<int> dp(x+1, 0);

    for(int i=0; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i-price[j] >= 0) {
                dp[i] = max(dp[i], pages[j] + dp[i-price[j]]);
            }
        }
    }

    // testing
    // for(int i=0; i<=x; i++)
    //     cout << dp[i] << " ";

    cout << dp[x];

    return 0;
}