#include <bits/stdc++.h>
using namespace std;

int currencies;
vector<string> names;
vector<vector<int>> rates;
vector<int> dist;
vector<int> pre;

/* 
initialize 𝑑𝑖𝑠𝑡(𝑠) ← 0, 𝑝𝑟𝑒(𝑠) ← 𝑛𝑢𝑙𝑙 and for each vertex 𝑢: 𝑑𝑖𝑠𝑡(𝑢) ← ∞,
𝑝𝑟𝑒(𝑢) ← 𝑛𝑢𝑙𝑙
iterate 𝑛 − 1 times:
    relax all edges, i.e., for each edge (𝑢, 𝜈):
    if 𝑑𝑖𝑠𝑡(𝜈) > 𝑑𝑖𝑠𝑡(𝑢) + 𝓁(𝑢, 𝜈) then
        𝑑𝑖𝑠𝑡(𝜈) ← 𝑑𝑖𝑠𝑡(𝑢) + 𝓁(𝑢, 𝜈) and 𝑝𝑟𝑒(𝜈) ← 𝑢
    abort when no 𝑑𝑖𝑠𝑡-value has changed
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> currencies;
    names.assign(currencies , "");
    rates.assign(currencies,vector<int>(currencies));
    dist.assign(currencies, INT_MAX);
    pre.assign(currencies, -1);

    for(int i = 0; i < currencies; i++){
        cin >> names[i];
    }
    for(int i = 0; i < currencies; i++){
        for(int j = 0; j < currencies; j++){
            double temp;
            cin >> temp;
            rates[i][j] = -((int)(temp*10000));
        }
    }
    dist[0] = 0;
    for(int i = 0; i < currencies; i++){
        for(int j = 0; j < currencies; j++){
            for(int k = 0; k < currencies; k++){
                if(dist[k] > dist[j] + rates[j][k]){
                    dist[k] = dist[j] + rates[j][k];
                    pre[k] = j;
                }
            }
        }
    }

    vector<int> seen(currencies);
    for(int j = 0; j < currencies; j++){
        for(int k = 0; k < currencies; k++){
            if(dist[k] > dist[j] + rates[j][k]){
                dist[k] = dist[j] + rates[j][k];
                pre[k] = j;

                int s = k;
                while(!seen[s]){
                    seen[s] = 1;
                    s = pre[s];
                }

                string ans = names[s];
                int c = s;
                int count = 1;
                while(pre[c] != s){
                    ans = names[pre[c]] + " " + ans;
                    c = pre[c];
                    count++;
                }

                cout << "money!" << endl;
                cout << count << endl;
                cout << ans;

                return 0;
            }
        }
    }
    cout << "noglitch" << endl;

}