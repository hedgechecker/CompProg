#include <bits/stdc++.h>
using namespace std;
bool parted(int arr[],int n,int parts){
    int last = arr[0];
    int currparts = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] > last){
            currparts++;
        }
        last = arr[i];
        if(currparts > parts){
            return false;
        }
    }
    return currparts == parts;
}
int main(){
    int len = 5;
    int arr[len] = {};
    for(int i = 0; i < len; i++){
        arr[i] = i+1;
    }
    int start[len+1] = {};
    sort(arr, arr + len);
    int parts = 2;
    int total = 0;
    // Generate all permuatation of an array
    do {
        if(parted(arr,len,parts)){
            start[arr[0]]++;
            // for (int i = 0; i < len; i++)
            //     cout << arr[i] << " ";
            // cout << endl;
            total++;
        }
        
    } while (next_permutation(arr, arr + len));

    for(int i = 1; i <= len; i++){
        cout << "Start "<< i << " IS" << start[i]<<endl;
    }
    cout << total << endl;
    return 0;

} 