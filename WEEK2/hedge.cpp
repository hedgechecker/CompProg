#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> poss(2001, vector<int>(2001,0));

long calcPoss(int n,int p){
    if(poss[n][p] != 0){
        return poss[n][p];
    }
    if(n == p || p == 1 || n == 1){
        poss[n][p] = 1;
        return 1;
    }
    if(p>n){
        cout << "index error" << n << " " <<p <<endl;
        return 0;
    }
    poss[n][p] = ((long long)p * calcPoss(n-1, p) + (long long)(n-p+1) * calcPoss(n-1, p-1)) % 998244353;
    return poss[n][p];
}
int main(){
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int n,p;
        cin >> n >> p;
        cout << calcPoss(n,p) << endl;
    }
}
