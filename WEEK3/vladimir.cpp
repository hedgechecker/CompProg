#include <bits/stdc++.h>
using namespace std;

void prefix(vector<int>& setup, vector<int>& lengths){
    int j = 0;
    lengths[0] = 0;
    for(int i = 1; i < setup.size(); i++){
        j = lengths[i-1];
        while(j>0 && setup[i] != setup[j]){
            cout << "Not the same "<< i << "  " <<j<<endl;
            j = lengths[j-1];
        }
        if(setup[i] == setup[j]){
            j++;
        }
        lengths[i] = j;
    }
}

bool checkPalin(vector<int> setup, int place){
    for(int i = 0; i < place; i++){
        if(setup[place-i-1]!=setup[place+i]){
            return false;
        }
    }
    return true;
}

int blocks, colors;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> blocks;
    cin >> colors;
    vector<int> setup(blocks);
    vector<int> lengths(blocks);
    for(int i = 0; i < blocks; i++){
        cin >> setup[i];
    }
    prefix(setup,lengths);
    for(int i = 0; i < blocks; i++){
        cout << " " << lengths[i];
    }
    cout << endl;
    for(int i = (blocks/2)*2; i > 2; i-=2){
        if(lengths[i-1] >= i/2){
            cout << blocks - i/2 << " ";
        }
    }
    cout << blocks << " " << endl;
    // for(int i = blocks/2; i > 0; i--){
    //     if(checkPalin(setup, i)){
    //         cout << (blocks-i) << " ";
    //     }
    // }
    // cout << blocks << " " << endl;
}