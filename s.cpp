#include <bits/stdc++.h>
using namespace std;
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T,n,m=1,l=0,r,in;
 vector<unsigned long long> arr(15625001);
 cin >>T;
 while(T--){
  cin >> n;
  vector<int> f(n);
  fill(arr.begin(), arr.end(), 0ULL);
  m =1;l=0;
  for(r=0;r<n;++r) {
   cin >> f[r];
   while(((arr[f[r]/64]) & (1ULL << (f[r]%64))) != 0){
    arr[f[l]/64] &= ~(1ULL << (f[l]%64));
    l++;
   } 
   arr[f[r]/64] |= (1ULL << (f[r]%64));
   m = max(m, r - l + 1);
  }
  cout << m << endl;
 }
}