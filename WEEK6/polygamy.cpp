#include <bits/stdc++.h>
using namespace std;

int nobles, bonds;
vector<list<int>> adjlist;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> nobles >> bonds;
    adjlist.resize(nobles);
    for(int i = 0; i < bonds; i++){
        int a,b;
        cin >> a >> b;
        adjlist[a].push(b);
        adjlist[b].push(a);
    }
}