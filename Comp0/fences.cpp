#include <bits/stdc++.h>
using namespace std;
int colors, orders, start, endj, color;
vector<int> input(100000000);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> colors;
    cin >> orders;
    cout << orders << "OOO";
    for(int i = 0; i < orders; i++){
        cin >> start;
        cin >> endj;
        cin >> color;
        for(int i = 0; i < endj-1; i++){
            input[i] = color;
        }
    }

    vector<int> amount(colors);
    for(unsigned long i = 0; i < 1000000000000; i++){
        if(input[i] == -1)continue;
        amount[input[i]]++;
    }   

    for(int i = 0; i < colors; i++){
        cout << amount[i] << endl;
    }



}