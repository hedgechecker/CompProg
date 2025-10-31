#include <bits/stdc++.h>
using namespace std;
struct Order {
  long st, en;
  int color, indexZ;
};

long long st, en;
int colors, orders, color;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> colors;
    cin >> orders;

    list<Order> orderList;   
    vector<long> amount(colors);

    for(int i = 0; i < orders; i++){
        cin >> st;
        cin >> en;
        cin >> color;
        if(st != en){
            orderList.push_back({st,en,color,i});
        }
    }

    // for (auto &o : orderList) {
    //     if (o.st == -1) continue;
    //     cout << o.st << " " << o.en << " color:" << o.color << " z:" << o.indexZ << "\n";
    // }
    // struct
    // {
    //     bool operator()(tuple<long,long,int,int> a, tuple<long,long,int,int> b) const { 
    //         return ((get<1>(a) - get<0> (a)) < (get<1>(b) - get<0> (b))) ;
    //     }
    // }
    // customLess;
    // sort(input.begin(), input.end(), customLess);

    for (auto it = orderList.begin(); it != orderList.end(); ++it) {
        auto &[st, en, color, zIndex] = *it;
        if (st == -1) continue;
        for (auto jt = orderList.begin(); jt != it;) {
            auto &[stj, enj, colorj, zIndexj] = *jt;

            if (jt == it || zIndexj >= zIndex || enj <= st || stj >= en) {
                ++jt;
                continue;
            }

            if (stj >= st && enj <= en) {
                jt = orderList.erase(jt);
            }else if (stj >= st && stj < en) {
                jt->st = en;
                ++jt;
            } else if (enj <= en && enj > st) {
                jt->en = st;
                ++jt;
            } else if (stj < st && enj > en) {
                Order rightPart = {en, enj, colorj, zIndexj};
                jt->en = st;
                orderList.insert(next(jt), rightPart);
                ++jt;
            } else {
                ++jt;
            }
        }
    }

    //  cout << "AFTER: "<<endl;
    //  for (auto &o : orderList) {
    //      cout << o.st << " " << o.en << " color:" << o.color << " z:" << o.indexZ << "\n";
    //  }

    for (auto &o : orderList) {
        amount[o.color] += (o.en - o.st); 
    }
    for (auto o : amount) {
        cout<<o<<endl;
    }
}