#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long num,a,b,c,d;
    cin >>num;
    cin >> a;
    if(num == 1){ cout << a << endl; return 0;}
    cin >> b;
    if(num == 2){ cout << max(a,b) << endl; return 0;}
    cin >> c;
    c += a;
    for(int i = 3; i < num; i++){
        cin >> d;
        d += max(b,a);a = b;b = c;c = d;
    }
    cout << max(c,b) << endl;
}