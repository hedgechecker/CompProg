#include <bits/stdc++.h>
using namespace std;

vector<long> includeDP, excludeDP;
vector<list<int>> adjlist;
vector<int> fun;
vector<int> visited;
void getFun(int id){
    if(visited[id])return;
    visited[id] = 1;
    includeDP[id] = fun[id];
    excludeDP[id] = 0;
    for(int child :  adjlist[id]){
        if(!visited[child]){
            getFun(child);
        }
        includeDP[id] += excludeDP[child];
        excludeDP[id] += max(includeDP[child], excludeDP[child]);
    }
}
int num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>num;
    adjlist.assign(num+10,{});
    fun.assign(num+10,0);
    includeDP.assign(num+10,0);
    excludeDP.assign(num+10,0);
    visited.assign(num+10,0);
    
    for(int i = 1; i < num+1; i++){
        cin >> fun[i];
    }
    for(int i = 2; i <= num; i++){
        int boss;
        cin >> boss;
        adjlist[boss].push_back(i);
    }

    getFun(1);
    cout << max(includeDP[1],excludeDP[1]) << endl;

}