#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int n = 10000;
    cout << 1 << endl << n << endl;
    srand(time(0));
    for(int i = 0; i < 10000; i++){
        //cout  << (rand()%10000001) << " ";
        if(i == 30){
            cout <<0<< " ";
        }else{
            cout  << i << " ";
        }
    }
}