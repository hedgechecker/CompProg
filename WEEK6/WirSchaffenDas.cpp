#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graphAdj;
vector<int> discoveryTime, lowLink, componentCount;
vector<bool> isCutVert;
vector<vector<int>> components;
stack<pair<int,int>> edgeStack;
int timer = 0;

void dfs(int node, int parent) {
    discoveryTime[node] = lowLink[node] = timer++;
    int childCount = 0;

    for (int neighbor : graphAdj[node]) {
        if (neighbor == parent) continue;

        if (discoveryTime[neighbor] == -1) {
            childCount++;
            edgeStack.push({node, neighbor});
            dfs(neighbor, node);

            lowLink[node] = min(lowLink[node], lowLink[neighbor]);

            // extract a BCC if AP condition holds
            if (lowLink[neighbor] >= discoveryTime[node]) {
                if (parent != -1)
                    isCutVert[node] = true;

                vector<int> comp;
                while (true) {
                    auto e = edgeStack.top(); edgeStack.pop();
                    comp.push_back(e.first);
                    comp.push_back(e.second);
                    if (e.first == node && e.second == neighbor)
                        break;
                }
                sort(comp.begin(), comp.end());
                comp.erase(unique(comp.begin(), comp.end()), comp.end());
                components.push_back(comp);
            }
        }
        else if (discoveryTime[neighbor] < discoveryTime[node]) {
            edgeStack.push({node, neighbor});
            lowLink[node] = min(lowLink[node], discoveryTime[neighbor]);
        }
    }

    if (parent == -1 && childCount > 1)
        isCutVert[node] = true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    graphAdj.assign(numNodes, {});
    discoveryTime.assign(numNodes, -1);
    lowLink.assign(numNodes, -1);
    componentCount.assign(numNodes, 0);
    isCutVert.assign(numNodes, false);
    components.assign(numNodes,vector<int>());

    for (int i = 0; i < numEdges; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graphAdj[a].push_back(b);
        graphAdj[b].push_back(a);
    }

    for (int i = 0; i < numNodes; i++) {
        if (discoveryTime[i] == -1) {
            dfs(i, -1);
        }
    }

    for (int i = 0; i < numNodes; i++) {
        if (isCutVert[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    int leafs = 0;
    for(auto c:components){
        if(c.size() == 0) continue;
        int cuts = 0;
        for(int i:c){
            if(isCutVert[i]) cuts++;
            cout << i+1 << " ";
        }
        cout << endl;
        if(cuts == 1)leafs++;
    }
    cout << leafs<<endl;
    //Create cut-Graph
    cout << ceil((double)leafs/(double)2) << endl;


    return 0;
}
