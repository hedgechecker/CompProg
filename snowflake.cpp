#include <bits/stdc++.h>
using namespace std;
long long flakes[150000] = {}; 


int nextIndex(int left, int right, int num){
    if(left > right){
        return left;
    }
    for(int i = left; i <= right; i++){
        if(flakes[i] == num){
            return i+1;
        }
    }
    return left;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, snowflakes, left, num, maxWindow;
    for(cin >> cases; cases--;){
        cin >> snowflakes;

        cin >> num;
        left = 0;
        maxWindow = 1;
        flakes[0] = num;

        for(int i = 1; i < snowflakes; i++){
            cin >> num;
            flakes[i] = num;
            left = nextIndex(left, i-1, num);
            maxWindow = ((i-left+1) > maxWindow)? (i-left+1): maxWindow;
        }
        cout << maxWindow << endl;
    }
}