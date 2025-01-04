#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main() {

    int n;
    cin >> n;

    if(n == 1){
        cout << "1";
    }
    else if(n <= 3) {
        cout << "NO SOLUTION";
        return 0;
    }
    else if(n == 4) {
        cout << "2 4 1 3";
    }
    else {
        if(n%2 == 0) {
            int temp = n;
            while(temp > 0) {
                cout << temp << " ";
                temp -= 2;
            }
            temp = n-1;
            while(temp > 0) {
                cout << temp << " ";
                temp -= 2;
            }
        }
        else {
            int temp = n-1;
            while(temp > 0) {
                cout << temp << " ";
                temp -= 2;
            }
            temp = n;
            while(temp > 0) {
                cout << temp << " ";
                temp -= 2;
            }
        }
    }

    return 0;
}