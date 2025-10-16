#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcases, length, currIndex, middleP;
    cin >> testcases;

    for(int i = 0; i < testcases; i++){
        cin >> length;
        middleP = (length/2) -1;
        int stepsize = middleP;

        string answer;
        bool curr = false, right=false;
        bool loop = true;

        while(loop){
            cout << "READ " << (middleP) << endl;
            cin >> answer;
            if(answer == "true"){
                curr = true;
            }else{
                curr = false;
            } 
            cout << "READ " << (middleP+1) << endl;
            cin >> answer;
            if(answer == "true"){
                right = true;
            }else{
                right = false;
            }
            stepsize/=2;
            if(stepsize <= 0){
                stepsize = 1;
            }
            if(curr && !right){
                loop = false;
                cout << "OUTPUT " << (middleP) << endl;
            } else if(!curr && !right){
                middleP -= stepsize; 
                if(middleP < 0){
                    middleP = 0;
                }
            } else if(curr && right){
                middleP += stepsize; 
                if(middleP > length){
                    middleP = length-2;
                }
            } else{
                if((length -middleP) < (middleP)){
                    middleP = middleP + ((length - middleP)/2);
                    stepsize = ((length -middleP)/2);
                }else{
                    middleP  = middleP/2;
                    stepsize = middleP/2;
                }
            }
        }
    }
}
