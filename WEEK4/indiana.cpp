#include <bits/stdc++.h>
using namespace std;

int cases, levers, hints;
vector<list<int>> adjlist;
vector<int> sorted;
bool check = false;

int topologicalSort(){
    vector<int> inDegree(levers+1, 0); 
    queue<int> q; 
    check = false;
    int visited = 0;
    for(int i = 1; i <= levers; i++){
        for (int j : adjlist[i]){
            inDegree[j]++;
        }
    }

    for (int i = 1; i <= levers; i++){
        if (inDegree[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()){   
        if(q.size() > 1){
            check = true;
        }
        int u = q.front();
        sorted[visited] = u; 
        q.pop();
        visited++;
        
        for (int i : adjlist[u]){
            inDegree[i]--;
            if (inDegree[i] == 0){
                q.push(i);
            }
        }
    }

    //Then there is a circle
    if(visited != levers){
        return -1;
    }
    if(check){
        return -2;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> cases;
    for(int c = 0; c < cases; c++){

        cin >> levers;
        cin >> hints;
        adjlist.assign(levers+1,{});
        sorted.assign(levers+1,0);

        for(int i = 0; i < hints; i++){
            int a,b;
            cin >> a;
            cin >> b;
            adjlist[a].push_back(b);
        }

        int t = topologicalSort();
        if(t == -1){
            cout<< "recheck hints" << endl;
        }else if (t == -2){
            cout << "missing hints" << endl;
        }else{
            for(int i = 0; i < levers; i++){
                cout << sorted[i] << " ";
            }
            cout << endl;
        }
    }
}