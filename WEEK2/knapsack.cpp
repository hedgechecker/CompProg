#include <bits/stdc++.h>
using namespace std;

int fill(int twos, int ones, int limit){
    if(twos * 2 + ones <= limit){
        return twos * 2 + ones - limit;
    }else{
        if(limit % 2 == 1){
            if(ones > 0){
                return 0;
            }else{
                return -1;
            }
        }else{
            return 0;
        }
    }


}  
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, M, c;
    int num[4] = {0,0,0,0};
    cin >> n;
    cin >> M;
    for(int i = 0; i < n; i++){
        cin >> c;
        num[c]++;
    }
    if(num[1]+2*num[2]+3*num[3] <= M){
        cout << num[1]+2*num[2]+3*num[3] <<endl;
        return 0;
    }

    int least = -99999999,off;
    if(num[3] == 0){
        least = fill(num[2], num[1], M);
    }
    for(int i = 0; i <= (M/3) && i<=num[3]; i++){
        off = fill(num[2], num[1], M-(i*3));
        //cout << "OFF" << off << endl;
        if(off == 0){
            cout << M << endl;
            return 0;
        }
        least = (off > least)? off : least;
        //cout << least << endl;
        if(off < -12){
            i += (-(off+12) / 3);
        }
    }
    cout << M+least << endl;
    return 0;

}
 