#include <bits/stdc++.h>
using namespace std;

int cities, streets;
int seenNo;
vector<list<int>> adjlist;
vector<int> smallestParent;

int kreissuche(int start){
    smallestParent[start] = start;
    for(int i : adjlist[start]){
        int k;
        if(smallestParent[i] != -1){
            k = smallestParent[i];
        }else{
            k = kreissuche(i);
        }
        if(k < smallestParent[start]){
            smallestParent[start] = k;
        }
    }
    return smallestParent[start];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> cities >> streets;
    adjlist.resize(cities);
    smallestParent.assign(cities,-1);
    for(int i = 0; i < streets; i++){
        int a,b;
        cin >> a >> b;
        adjlist[a-1].push_back(b-1);
    }
    int currStart = 0;
    seenNo = 1;
    while(currStart < cities){
        if(smallestParent[currStart] != -1) {
            currStart++;
            continue;
        }
        kreissuche(currStart);
    }

    for(int i = 0; i < cities; i++){
        //fix smallestValues
        int curr = i;
        while(smallestParent[curr] != curr){
            curr = smallestParent[curr];
        }
        smallestParent[i] = curr;
    }
    set<int> s;
    for(int i = 0; i < cities; i++){
        s.insert(smallestParent[i]);
        //cout << smallestParent[i] << " ";
    }
    //cout << endl;
    cout << s.size() << endl;
}