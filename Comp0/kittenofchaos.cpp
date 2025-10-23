#include <bits/stdc++.h>
using namespace std;
int num = 0;
string  transforms,tempstring;
vector<char> input(500000);
bool r = false, h=false ,v=false;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tempstring;
    for(long unsigned int i = 0; i < tempstring.length();i++){
        input[i] = tempstring.at(i);
    }
    num = tempstring.length();

    

    cin  >> transforms;

    for(long unsigned int i = 0; i < transforms.length(); i++){
        char curr = transforms.at(i);
        if(curr == 'r')r=!r;
        if(curr == 'v')v=!v;
        if(curr == 'h')h=!h;
    }

    if(r){
       v=!v;
       h=!h;
    }

    //cout << v << " " << h << " " << r;

    if(v){
     for(int i = 0; i < num; i++){
        if(input[i] == 'b'){input[i] = 'p';}
        else if(input[i] == 'p'){input[i] = 'b';}
        else if(input[i] == 'q'){input[i] = 'd';}
        else if(input[i] == 'd'){input[i] = 'q';}
        }   
    }
    if(h){
     for(int i = 0; i < num/2; i++){
        char temp = input[i];
        if(input[num-i-1] == 'b'){
            input[i] = 'd';
            if(temp == 'b')input[num-i-1] = 'd';
            if(temp == 'p')input[num-i-1] = 'q';
            if(temp == 'q')input[num-i-1] = 'p';
            if(temp == 'd')input[num-i-1] = 'b';
        }
        else if(input[num-i-1] == 'p'){
            input[i] = 'q';
            if(temp == 'b')input[num-i-1] = 'd';
            if(temp == 'p')input[num-i-1] = 'q';
            if(temp == 'q')input[num-i-1] = 'p';
            if(temp == 'd')input[num-i-1] = 'b';
        }
        else if(input[num-i-1] == 'q'){
            input[i] = 'p';
            if(temp == 'b')input[num-i-1] = 'd';
            if(temp == 'p')input[num-i-1] = 'q';
            if(temp == 'q')input[num-i-1] = 'p';
            if(temp == 'd')input[num-i-1] = 'b';
        }
        else if(input[num-i-1] == 'd'){
            input[i] = 'b';
            if(temp == 'b')input[num-i-1] = 'd';
            if(temp == 'p')input[num-i-1] = 'q';
            if(temp == 'q')input[num-i-1] = 'p';
            if(temp == 'd')input[num-i-1] = 'b';
        }
    }   
    if(num%2 == 1){
        if(input[num/2] == 'b'){input[num/2] = 'd';}
        else if(input[num/2] == 'p'){input[num/2] = 'q';}
        else if(input[num/2] == 'q'){input[num/2] = 'p';}
        else if(input[num/2] == 'd'){input[num/2] = 'b';}
    }

    }

    for(int i = 0; i <num; i++){
        cout << (char)input[i];
        }
        cout << endl;
}