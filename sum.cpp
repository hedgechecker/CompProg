#include <bits/stdc++.h>
using namespace std;
int main(int argc, char*argcv[]){
   ios_base::sync_with_stdio(false);// keine Synchronisation mit scanf/printf
   cin.tie(0);// kein automatischer Ausgabe-Flush vor Eingabe

   int x;
   cin >> x;

   long sum = 0;
   for(int i=0;i<x;i++){
      int n;
      cin >> n;
      sum += n;
   }
   cout << sum;
}