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
    vector<Problem> problems(num);
    vector<Problem> reverseProblems(num);
    vector<int> problemPlacement(num);
    for(int i = 0; i < num; i++){
        int l,r;
        cin >> l;
        cin >> r;
        problems[i] = {l,r,i+1};
        reverseProblems[i] = {l,r,i+1};
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
    sort(problems.begin(), problems.end(), customLess);

    struct
    {
        bool operator()(Problem a, Problem b) const { 
            if(a.right > b.right){
                return true;
            }else if(b.right == a.right){
                return (a.left >= b.left);
            }else{
                return false;
            }
        }
    }
    customMore;
    sort(reverseProblems.begin(), reverseProblems.end(), customMore);

    unordered_set<int> placed {};
    int l = 0, r = 0;
    for(int i = 0; i < num/2; i++){
        while(placed.count(problems[l].index) > 0){
            l++;
        }
        problemPlacement[i] = problems[l].index;
        placed.insert(problems[l].index);

        while(placed.count(reverseProblems[r].index) > 0){
            r++;
        }
        problemPlacement[num-1-i] = reverseProblems[r].index;
        placed.insert(reverseProblems[r].index);
    }
    
    if(num%2 != 0){
        while(placed.count(problems[l].index) > 0){
            l++;
        }
        problemPlacement[(num/2)] = problems[l].index;
    }
    for(int i = 0; i < num; i++){
        cout << problemPlacement[i] << " ";
    }
    cout << endl;


}