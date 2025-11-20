#include <bits/stdc++.h>
using namespace std;

struct Order{
    int indexZ;
    int color;
    bool operator<(const Order o) const { 
        return indexZ < o.indexZ ;
    } 
};

struct Event{
    long long pos;
    int start;
    int ordernum;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int colors,orders;
    cin >> colors >> orders;

    vector<Order> orderList(orders);   
    vector<long long> amount(colors, 0);
    vector<Event> events(2*orders);

    for(int i = 0; i < orders; i++){
        long st, en;
        int color;
        cin >> st >> en >> color;
        orderList[i] = {i,color};
        events[2*i] = {st, 1,i};
        events[2*i +1] = {en, 0,i};
    }

    // for(int i= 0; i < orders; i++){
    //     cout << orderList[i].indexZ << " " << orderList[i].color << endl;
    // }

    struct {
        bool operator()(Event a, Event b) const { 
            if (a.pos == b.pos) return a.start > b.start;
            return a.pos < b.pos;
        }
    }
    customLess;
    sort(events.begin(), events.end(), customLess);

    set<tuple<int,int>> active;
    long long prevPos = events.front().pos;

    //long long prevPos = 0;
    for(const Event &e : events){
        long long currPos = e.pos;

        if (!active.empty()) {
            tuple<int,int> it = *(prev(active.end()));
            int topColor = get<1>(it);
            amount[topColor] += ((long long)currPos - (long long)prevPos);
        }

        Order o = orderList[e.ordernum];
        if(e.start){
            active.insert({o.indexZ,o.color});
        }else {
            active.erase({o.indexZ,o.color});
        }

        prevPos = currPos;
    }

    for (long long a : amount){
        cout << a << "\n";

    }
    return 0;
}