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
        int types[coins];
        vector<int> steps(7001, -1);
        for(int j = 0; j < coins; j++){
            cin >> types[j];
        }
        //fillSpaces(coins, debt);
        queue<int> q;
        int val;
        int currstep = (debt/types[coins-1])+1;
        queue<int> newq;
        
        q.push(debt - ((debt/types[coins-1]) * types[coins-1]));
        //cout<<"FRONT"<<q.front()<<endl;
        if(q.front() == 0){
            cout << currstep-1 <<endl;
            goto label1;
        }
        while(true){
            while(!q.empty()){
                val = q.front();
                q.pop();
                for(int j = 0; j < coins; j++){
                    if(val + types[j] <= 7000){
                        if(steps[val + types[j]] > -1){
                            
                        }else{
                            steps[val + types[j]] = currstep;
                            newq.push(val + types[j]);
                            //cout <<"NewVal "<<newq.back() <<endl;
                        }
                    }
                    if(val - types[j] > 0){
                        if(steps[val - types[j]] > -1){
                            
                        }else{
                            steps[val - types[j]] = currstep;
                            newq.push(val - types[j]);
                            //cout <<"NewVal "<<newq.back() <<endl;
                        } 
                    }
                    if(val -types[j] == 0){
                        cout << currstep << endl;
                        goto label1;
                    }
                }
            }
            q = newq;
            queue<int> newq;
            //cout << "NEWQUEWE "<< q.front() << endl;
            currstep++;
        }
        label1:
        if(true){}

    }
}