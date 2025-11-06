#include <bits/stdc++.h>
using namespace std;

struct Problem{
    int left, right, index;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    priority_queue<tuple<int,int,int>> problems;
    vector<int> problemPlacement(num);
    for(int i = 0; i < num; i++){
        int l,r;
        cin >> l;
        cin >> r;
        problems.push({-l,-r,i+1});
    }
    struct
    {
        bool operator()(Problem a, Problem b) const { 
            if(a.left < b.left){
                return true;
            }else if(a.left == b.left){
                return (a.right <= b.right);
            }else{
                return false;
            }
        }
    }
     customLess;
    // sort(problems.begin(), problems.end(), customLess);
    int lastStart = 1;
    // for(int i = 0; i < num; i++){
    //     cout << "Problem "<< problems[i].index << endl;
    // }
    for(int i = 0; i < num; i++){
        problemPlacement[i] = get<2>(problems.top());
        problems.pop();
        while(!problems.empty() && get<0>(problems.top()) <= lastStart){
            tuple<int,int,int> p = problems.top();
            problems.push({lastStart+1, get<1>(p), get<2>(p)});
            problems.pop();
        }
        lastStart++;
    }
    for(int i = 0; i < num; i++){
        cout << problemPlacement[i] << " ";
    }
    cout << endl;


}