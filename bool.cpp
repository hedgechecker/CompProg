#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcases, length, middleP, oneIndex, zeroIndex;
    string answer;

    cin >> testcases;

    for(int i = 0; i < testcases; i++){
        cin >> length;
        middleP = (length/2) -1;
        int stepsize = middleP/2;
        oneIndex = 0;
        zeroIndex = length/2;

        bool curr = false, right=false;

        while(oneIndex +1 != zeroIndex){
            cout << "READ " << (middleP) << endl;
            cin >> answer;
            if(answer == "true"){
                oneIndex = middleP;
                middleP += stepsize;
            }else{
                zeroIndex = middleP;
                middleP -= stepsize;
            } 
            stepsize/=2;
            stepsize = (stepsize <= 0)?1:stepsize;
        
            
                
            } 
            cout << "OUTPUT " << (middleP) << endl;
    }
}
