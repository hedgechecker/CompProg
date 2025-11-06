#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int numCont;
    cin >> numCont;
    
    vector<int> difficulties(numCont);
    vector<int> longestincreasing(numCont);
    vector<int> longestdecreasing(numCont);
    for(int i = 0; i < numCont; i++){
        int d;
        cin >> difficulties[i];
    }
    
    longestincreasing[0] = 1;
    for(int i = 1; i < numCont; i++){
        int curr = difficulties[i];
        int nextsmallest = -1, nextsmallestValue = 0;
        for(int j= 0; j < i; j++){
            if(difficulties[j] < difficulties[i] && longestincreasing[j] > nextsmallestValue){
                nextsmallest = j;
                nextsmallestValue = longestincreasing[j];
                //cout << "FOUND" << j << " " << nextsmallestValue;
            }
        }
        if(nextsmallest > -1){
            longestincreasing[i] = nextsmallestValue +1;
        }else{
            longestincreasing[i] = 1;
        }
    }
    // for(int i = 0; i < numCont; i++){
    //     cout << longestincreasing[i] << " ";
    // }
    // cout << endl;

    longestdecreasing[numCont-1] = 1;
    for(int i = numCont-2; i >= 0; i--){
        int curr = difficulties[i];
        int nextsmallest = -1, nextsmallestValue = 0;
        for(int j= numCont-1; j > i; j--){
            if(difficulties[j] < difficulties[i] && longestdecreasing[j] > nextsmallestValue){
                nextsmallest = j;
                nextsmallestValue = longestdecreasing[j];
                //cout << "FOUND" << j << " " << nextsmallestValue;
            }
        }
        if(nextsmallest > -1){
            longestdecreasing[i] = nextsmallestValue +1;
        }else{
            longestdecreasing[i] = 1;
        }
    }
    // for(int i = 0; i < numCont; i++){
    //     cout << longestdecreasing[i] << " ";
    // }
    // cout << endl;

    int max = 1;
    for(int i = 0; i < numCont; i++){
        if(longestincreasing[i]+longestdecreasing[i] > max){
            max = longestincreasing[i]+longestdecreasing[i];
        }
    }
    cout << max-1 << endl;
    
}