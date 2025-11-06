#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num, diff, n;
    cin >> num;
    cin >> diff;
    priority_queue<int> difficulties;
    for(int i = 0; i < num; i++){
        cin >> n;
        difficulties.push(n);
    }
    double erwartung = 0.0;
    long long total = 0;
    int totalNum = 0;
    for(int i = 0; i < num; i++){
        erwartung = ((double)(total + difficulties.top())) / (totalNum+1); 
        if(erwartung >= (double)diff){
            total += difficulties.top();
            difficulties.pop();
            totalNum++;
        }else{
            cout << totalNum << endl;
            return 0;
        }
    }
    cout << totalNum << endl;
    return 0;
}