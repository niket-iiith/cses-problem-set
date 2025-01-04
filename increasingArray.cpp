#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    ll n;
    cin >> n;

    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    ll moves = 0;
    for(int i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) {
            moves += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }

    cout << moves;

    return 0;
}