#include <bits/stdc++.h>
using namespace std;

struct Problem{
    bool operator<(const Problem p) const { 
        return right > p.right ;
    } 
    int left, right, index;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    vector<Problem> problems(num);
    vector<int> problemPlacement(num);
    for(int i = 0; i < num; i++){
        int l,r;
        cin >> l;
        cin >> r;
        problems[i] = {l,r,i+1};
    }
    struct
    {
        bool operator()(Problem a, Problem b) const { 
            if(a.left < b.left){
                return true;
            }else if(a.left == b.left){
                return (a.right < b.right);
            }else{
                return false;
            }
        }
    }
    customLess;
    sort(problems.begin(), problems.end(), customLess);
    
    priority_queue<Problem> active;
    int prob = 0;
    for(int curr = 0; curr < num; curr++){
        while(prob < num && problems[prob].left == curr+1 ){
            active.push(problems[prob]);
            prob++;
        }    
        problemPlacement[curr] = active.top().index;
        active.pop();
    }

    for(int i = 0; i < num; i++){
        cout << problemPlacement[i] << " ";
    }
    cout << endl;
}