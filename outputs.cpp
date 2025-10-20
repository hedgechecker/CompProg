#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    for(int i = 0; i < 500; i++){
        cout << rand()%1001 << rand() << " ";
    }
}