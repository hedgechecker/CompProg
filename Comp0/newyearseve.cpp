#include <bits/stdc++.h>
using namespace std;
int num, card1, card2, card3;
int total1, total2, total3, total0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num >> card1 >> card2 >> card3;
    total0 = num * 100;
    total1 = num * 75 + card1;
    total2 = num * 50 + card2;
    total3 = card3;

    int min = total0;
    min = (min < total1)? min : total1;
    min = (min < total2)? min : total2;
    min = (min < total3)? min : total3;

    if(min  == total0){
        cout << "no Bahncard";
    } else if(min  == total1){
        cout << "Bahncard 25";
    }else if(min  == total2){
        cout << "Bahncard 50";
    }else if(min  == total3){
        cout << "Bahncard 100";
    }
}