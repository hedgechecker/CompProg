#include <bits/stdc++.h>
using namespace std;
int houses, pies, temp, minVal = 10000000,maxVal = 0, neededpies = 0, divisor = 1;
int leftP, rightP,step;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> houses;
    cin >> pies;
    vector<int> input(houses, 0);
vector<int> normalized(houses, 0);

    for(int i = 0; i < houses; i++){
        cin >> temp;
        input[i] = temp;
        maxVal = (maxVal > temp)? maxVal : temp;
        minVal = (minVal < temp)? minVal : temp;
    }
    bool skip =false;
    rightP = maxVal;
    leftP = minVal;
    int count = 0;
    int m = rightP/2;
    step = ceil((double)(rightP-leftP)/2);
    while(count < 4 && m>0){
        skip = false;
        step = step/2;
        if(step == 0){step = 1; count++;};
        neededpies = 0;
        int div = m;
        ////     <<"CURRDIV" << div <<endl;
        for(int i = 0; i < houses; i++){
            ////cout << "CKSA "<<ceil((double)input[i]/(double)div);
            neededpies += ceil((double)input[i]/(double)div);
            //cout<<"NEEDED"<<neededpies <<endl;
            if(neededpies > pies){
                //cout <<"Loopend" << endl;
                m += step;
                skip = true;
                break;
            }
        }
        if(!skip){m-=step;}
        //cout<<"left"<<leftP<< "rigth" <<rightP<<"Step"<<step<< endl;
        

    }

    neededpies = 0;
        int div = m;
    for(int i = 0; i < houses; i++){
            ////cout << "CKSA "<<ceil((double)input[i]/(double)div);
            neededpies += ceil((double)input[i]/(double)div);
            //cout<<"NEEDED"<<neededpies <<endl;
            if(neededpies > pies){
                cout << m+1 <<endl;
                //cout <<"Loopend" << endl;
                return 0;
            }
        }
   
        cout << (m) <<endl;

    ////cout <<" MaxValdIv " << leftP << endl;
    

}