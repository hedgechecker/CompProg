#include <bits/stdc++.h>
using namespace std;
int houses, pies, temp,maxVal = 0;
int L, R,step,m;

int getneededCakes(int piecesPerCake, vector<int> input){
    int neededpies = 0;
    for(int i = 0; i < houses; i++){
        ////cout << "CKSA "<<ceil((double)input[i]/(double)div);
        neededpies += ceil((double)input[i]/(double)piecesPerCake);
        //cout<<"NEEDED"<<neededpies <<endl;
        if(neededpies > pies){
            //cout <<"Loopend" << endl;
            break;
        }
    }
    return neededpies;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> houses;
    cin >> pies;
    vector<int> input(houses, 0);

    for(int i = 0; i < houses; i++){
        cin >> temp;
        input[i] = temp;
        maxVal = (maxVal > temp)? maxVal : temp;
    }
    int lastL = 1, lastR = maxVal;
    R = maxVal;
    L = 1;
    while (L < R){
        m = L + ((R - L) / 2);
        int neededCakes = getneededCakes(m, input); 
        //cout << "Left: "<< L << " | Right: "<< R << " | Middle: " <<m << " | Value: " << neededCakes << endl;
        if (neededCakes > pies){
            L = m + 1;
        }
        else if(neededCakes < pies){
            R = m;
        } else{
            R = m;
        }
        if(lastL == L && lastR ==R)return 0;
        lastL = L;
        lastR = R;
    } 
    cout <<  L <<endl; 


}