#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int length, numEaten;
    cin >> length;
    cin >> numEaten;
    vector<char> input(length);
    vector<tuple<char,int>> count(length);

    for(int i = 0; i < length; i++){
        cin >> input[i];
        count[i] = {input[i], i};
    }
    struct
    {
        bool operator()(tuple<char,int> a, tuple<char,int> b) const { 
            if(get<0>(a) < get<0>(b)){
                return true;
            }else if(get<0>(a) > get<0>(b)){
                return false;
            }else{
                if(get<1>(a) < get<1>(b)){
                    return true;
                }else{
                    return false;
                }
            }
        }
    }
    customLess;
    sort(count.begin(), count.end(), customLess);
    // cout << "AFTER: "<<endl;
    // for (auto o : count) {
    //     cout << get<0>(o) << " " << get<1>(o) << endl;
    // }

    for(int i = 0; i < numEaten; i++){
        input[get<1>(count[i])] = '-';
    }
    for(int i = 0; i < length; i++){
        if(input[i] != '-'){
            cout << input[i];
        }
    }
    cout << endl;
}