#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, debt, coins;
    cin >> cases;
    for(int i = 0; i < cases; i++){
        cin >> debt;
        cin >> coins;
        int coinTypes[coins];
        vector<int> steps(debt+20000, -1);
        queue<int> q;
        for(int j = 0; j < coins; j++){
            cin >> coinTypes[j];
        }
        q.push(debt);
        steps[debt] = 0;
        while(steps[0] == -1 && !q.empty()){
            int curr = q.front();
            q.pop();
            for(int i = 0; i < coins; i++){
                if(curr - coinTypes[i] >= 0 && steps[curr-coinTypes[i]] == -1){
                    steps[curr-coinTypes[i]] = steps[curr] + 1;
                    q.push(curr-coinTypes[i]);
                }
                if(curr + coinTypes[i] < debt+20000 && steps[curr+coinTypes[i]] == -1){
                    steps[curr+coinTypes[i]] = steps[curr] + 1;
                    q.push(curr+coinTypes[i]);
                }
            }
        }
        // for(int i = 0; i<= debt; i++){
        //     cout << "I "<< i <<" Contebt: "<< steps[i] << endl;
        // }
        cout << steps[0] <<endl;
    }
}