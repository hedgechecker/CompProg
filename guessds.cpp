#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int value = 0;
    cout << "? insert 4" << endl;
    cout << "? insert 2" << endl;
    cout << "? insert 2" << endl;
    cout << "? insert 6" << endl;
    cout << "? remove" << endl;
    cin >> value;
    if(value == 4){
        cout << "! queue" << endl;
        return 0;
    } else if(value == 6){
        cout << "! stack" << endl;
        return 0;
    }
    cout << "? remove" << endl;
    cin >> value;
    if(value == 2){
        cout << "! pq" << endl;
        return 0;
    }
    cout << "! set" << endl;
    return 0;
}