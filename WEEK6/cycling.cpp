/*
1: select arbitrary starting vertex 𝑠
2: 𝐹 is a tree consisting only of 𝑠
3: while 𝐹 has less than 𝑛 vertices do
4: add shortest edge of 𝐺 that leaves 𝐹 to 𝐹
5: end while
6: return edge set of 𝐹
*/

#include <bits/stdc++.h>
using namespace std;

int cities,paths;
vector<int> elevation;
vector<vector<int>> adjmatrix;
vector<int> seen;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> cities >> paths; 
    elevation.assign(cities, 0);
    seen.assign(cities, 0);
    adjmatrix.assign(cities, vector<int>(cities,-1));
    for(int i = 0 ; i < cities; i++){
        cin >> elevation[i];
    }
    for(int i = 0; i < paths; i++){
        int a,b;
        cin >> a >> b;
        adjmatrix[a][b] = abs(elevation[a]-elevation[b]);
        adjmatrix[b][a] = abs(elevation[a]-elevation[b]);
    }

    priority_queue<tuple<int,int,int>> q;
    seen[0] = 1;
    int totalheight = 0;
    for(int i = 0; i < cities; i++){
        if(adjmatrix[0][i] >= 0){
            q.push({-adjmatrix[0][i], 0, i});
            //cout << "Pushed" << -adjmatrix[0][i] << " " << 0 << " " << i << endl;
        }
    }
    for(int i = 0; i < cities-1; i++){
        while(!q.empty() && seen[get<2>(q.top())]){
            q.pop();
        }
        if(q.empty()){
            cout << "Komisch" << endl;
            return 0;
        }
        auto[l,a,b] = q.top();
        totalheight += -l;
        seen[b] = 1;
        for(int j = 0; j < cities; j++){
            if(!seen[j] && adjmatrix[b][j] >= 0){
                q.push({-adjmatrix[b][j], b, j});
                //cout << "Pushed" << -adjmatrix[b][j] << " " << b << " " << j << endl;
            }
        }
    }
    cout << totalheight << endl;

}