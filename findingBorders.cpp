#include<bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    for (int i = 1; i<s.size(); i++) {
        string prefix = s.substr(0, i);
        string suffix = s.substr(s.size() - i, i);
        if(prefix.compare(suffix) == 0)
            cout << prefix.size() << " ";
    }

    return 0;
}