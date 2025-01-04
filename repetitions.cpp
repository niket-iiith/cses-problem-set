#include<bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int reps = 1;
    int ans = 1;
    for(int i=1; i<s.size(); i++) {
        if(s[i] == s[i-1])
            reps++;
        else 
            reps = 1;
        ans = max(ans, reps);
    }

    cout << ans;

    return 0;
}