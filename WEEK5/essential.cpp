#include <bits/stdc++.h>
using namespace std;

int cities, streets;
vector<int> dist;
vector<int> pre;
vector<int> seen;
vector<list<tuple<int,int,int>>> adjlist;

priority_queue<pair<int,int>> minVert;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> cities >> streets;
    dist.assign(cities, INT_MAX);
    seen.assign(cities, 0);
    pre.assign(cities, -1);
    adjlist.resize(cities);

    for(int i = 0; i < streets; i++){
        int c1, c2, l;
        cin >> c1 >> c2 >> l;
        adjlist[c1-1].push_back({c2-1,l,i});
        adjlist[c2-1].push_back({c1-1,l,i});
    }
    dist[0] = 0;

    minVert.push({-0,0});

    while(!minVert.empty()){
        auto[l,c] = minVert.top();
        minVert.pop();

        if(seen[c]){
            continue;
        }
        seen[c] = 1;

        for(auto[c2,l2,x] : adjlist[c]){
            if((-l) + l2 < dist[c2]){
                dist[c2] = -(l) + l2;
                pre[c2] = c;
                minVert.push({-(dist[c2]), c2});
            }
        }
    }

    cout << dist[1] << endl;

    vector<int> shortest(cities, 0);
    list<int> partshort;
    priority_queue<int> indexshort;
    partshort.push_back(1);
    while(!partshort.empty()){
        int cit = partshort.front();
        partshort.pop_front();
        for(auto[c,l,x] : adjlist[cit]){
            //if(shortest[c]) continue;
            if(l + dist[c] == dist[cit]){
                partshort.push_back(c);
                indexshort.push(-x);
            }
        }
        shortest[cit] = 1;
    }
    // for(int i = 0; i < cities; i++){
    //     if(shortest[i]){
    //         cout << i+1 << " " ;
    //     }
    // }

    // cout << endl;
    while(!indexshort.empty()){
        cout << -indexshort.top()+1 << " " ;
        indexshort.pop();
    }
}