#include <bits/stdc++.h>
using namespace std;
struct Order {
  long st, en;
  int color, indexZ;
};
template<typename T>
void fillremaining(T &activeOrders, Order * curr, Order * next, vector<long int> * amount){
cout << "Added "<< curr->en -curr->st << " To aslor "<< curr->color << endl;
    (*amount)[curr->color] += curr->en -curr->st;
    inset:while( !activeOrders.empty() && activeOrders.top().en <= curr->en){
        cout << "Popped" << activeOrders.top().st << " " << activeOrders.top().en <<endl;
        activeOrders.pop();
    }
    if(!activeOrders.empty()){
        Order temp = activeOrders.top();
        cout << "NEXT INPUT" << max(curr->en,temp.st) << " " << temp.en  << " " << temp.color <<endl;
        temp.st = max(curr->en,temp.st);
        curr->st = temp.st;
        curr->en = temp.en;
        curr->indexZ = temp.indexZ;
        curr->color = temp.color;
        if(curr->en < next->st){
            cout <<"AGAIN " << endl;
                cout <<"Added "<< curr->en -curr->st << " To COaSdlor "<< curr->color << endl;
            (*amount)[curr->color] += curr->en -curr->st;
            goto inset;
        }
                 
    }
    if(curr->indexZ > next->indexZ){
        
    }else{
    cout << "Added "<< min(next->st, curr->en) -curr->st << " To COlor "<< curr->color << endl;
        (*amount)[curr->color] += min(next->st, curr->en) - curr->st;
        curr->st = next->st;
        curr->en = next->en;
        curr->indexZ = next->indexZ;
        curr->color = next->color;
    }

    

}


long  st, en;
int colors, orders, color;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> colors;
    cin >> orders;

    vector<Order> orderList(orders);   
    vector<Order> orderEnds(orders);   
    vector<long> amount(colors);

    for(int i = 0; i < orders; i++){
        cin >> st;
        cin >> en;
        cin >> color;
            orderList[i] = {st,en,color,i};
            orderEnds[i] = {st,en,color,i};
    }

    // for (auto &o : orderList) {
    //     if (o.st == -1) continue;
    //     cout << o.st << " " << o.en << " color:" << o.color << " z:" << o.indexZ << "\n";
    // }
    struct
    {
        bool operator()(Order a, Order b) const { 
            return ( a.st) < (b.st) ;
        }
    }
    customLess;
    struct
    {
        bool operator()(Order a, Order b) const { 
            return ( a.en) < (b.en) ;
        }
    }
    customEnd;
    sort(orderList.begin(), orderList.end(), customLess);
    sort(orderEnds.begin(), orderEnds.end(), customEnd);

    for(auto &o : orderList){
        cout << o.st << " " << o.en << " color:" << o.color << " z:" << o.indexZ << "\n";
    }
    Order curr = orderList[0];
    Order next; 


auto customZ = [](const Order &a, const Order &b) {
    return a.indexZ < b.indexZ;  // higher z = higher priority
};

    priority_queue<Order, vector<Order>, decltype(customZ)> activeOrders(customZ);

    activeOrders.push(orderList[0]);
    for(int i = 1; i < orders; i++){
        next = orderList[i];

        if(next.st >= curr.en){
            fillremaining(activeOrders, &curr, &next, &amount);
            activeOrders.push(orderList[i]);
            
            cout << "Pushed" << orderList[i].st << " " << orderList[i].en <<endl;
            
            continue;
        }
        if(next.indexZ > curr.indexZ){
            amount[curr.color] += next.st -curr.st;
    cout << "Added "<< next.st -curr.st << " T0 COlor "<< curr.color << endl;

            curr = next;
            cout << "Current " << curr.st << " " << curr.en <<endl;

        }
        activeOrders.push(orderList[i]);
        cout << "Pushed" << orderList[i].st << " " << orderList[i].en <<endl;
    }
    amount[curr.color] += curr.en - curr.st;
    for(int i : amount){
        cout << i << endl;
    }
}