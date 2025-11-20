#include <bits/stdc++.h>
using namespace std;

int stations, connections, queries;
vector<vector<long long>> adjlist;
vector<int> changeTime;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> stations >> connections >> queries;
    changeTime.assign(stations,0);
    adjlist.assign(stations, vector<long long>(stations, LONG_MAX));
    for(int i = 0; i < stations; i++){
        cin >> changeTime[i];
        adjlist[i][i] = 0;
    }
    for(int i = 0; i < connections; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adjlist[a][b] = w;
    }
    for(int k = 0; k < stations; k++){
        for(int i = 0; i < stations; i++){
            for(int j = 0; j < stations; j++){
                if(adjlist[i][k] >= LONG_MAX || adjlist[k][j] >= LONG_MAX){
                    continue;
                }
                adjlist[i][j] = min(adjlist[i][j] , adjlist[i][k] + adjlist[k][j] +(long long)changeTime[k]);
            }
        }
    }

    for(int i = 0; i < queries; i++){
        int a,b;
        cin >> a >> b;
        if(adjlist[a][b] >= LONG_MAX){
            cout << "oo" << endl;
        }else{
            cout << adjlist[a][b] << endl;
        }
    }
}