#include <bits/stdc++.h>
using namespace std;

struct Order{
    long st,en;
    int color,indexZ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> colors;
    cin >> orders;

    vector<Order> orderList(orders);   
    vector<long> amount(colors);

    for(int i = 0; i < orders; i++){
        cin >> st;
        cin >> en;
        cin >> color;
        orderList[i] = {st,en,color,i};
    }

    struct {
        bool operator()(Order a, Order b) const { 
            return ( a.st) > (b.st) ;
        }
    }
    customLess;
    sort(orderList.begin(), orderList.end(), customLess);

}