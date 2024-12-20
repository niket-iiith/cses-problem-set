#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cassert>
using namespace std;
 
string result = "";
 
void dfs(vector<vector<char> >& building, int i, int j, int n, int m, string path) 
{
    if(i < 0 || i >= n || j < 0 || j >= m || building[i][j] == '#')
        return;
 
    // cout<<"path = "<<path<<endl;
    // cout<<"result = "<<result<<endl;
 
    if(building[i][j] == 'B') {
        if(result.size() == 0 || result.size() > path.size()) 
            result = path;
        return;
    }
 
    building[i][j] = '#';
 
    dfs(building, i+1, j, n, m, path+"D");
    dfs(building, i-1, j, n, m, path+"U");
    dfs(building, i, j+1, n, m, path+"R");
    dfs(building, i, j-1, n, m, path+"L");
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<char> > building(n, vector<char>(m));
    char temp;
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> temp;
            building[i][j] = temp; 
        }
    }
 
    string path = "";
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(building[i][j]=='A'){
                dfs(building, i, j, n, m, path);
            }
        }
    }
 
    if(result.size() == 0) cout<<"NO";
    else 
    {
        cout<<"YES\n";
        cout<<result.size()<<endl;
        cout<<result;
    }
 
    return 0;

}