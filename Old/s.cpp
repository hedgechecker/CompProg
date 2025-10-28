#include <bits/stdc++.h>
using namespace std;
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T,n,m=1,l=0,r,in;
 bitset<1000001> seen;
 vector<unsigned long long> arr(15625001);
 vector<int> tag(15625001, -1);
  vector<int> f(n); 
 int curT = 0;
 cin >>T;
 while(T--){
  cin >> n;
  m =1;l=0;
  for(r=0;r<n;++r) {
    f.resize(n);
   cin >> f[r];
   int idx = f[r] >> 6, bit = f[r] & 63;
    if(tag[idx] != curT){
        arr[idx] = 0;
        tag[idx] = curT;
    }
   while(((arr[idx]) & (1ULL << (bit))) != 0){
    arr[f[l]>>6] &= ~(1ULL << (f[l]&63));
    l++;
   } 
   arr[idx] |= (1ULL << (bit));
   m = max(m, r - l + 1);
  }
  cout << m << "\n";
  curT ++;
 }
}