#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T,n,m=1,l=0,r;
 cin >>T;
 while(T--){
  cin >> n;
  vector<int> f(n);
  gp_hash_table<int, null_type> w;
 // w.reserve(n);
  m =1;l=0;
  for(r=0;r<n;++r) {
   cin >> f[r];
   while (w.find(f[r])!=w.end()) {
    w.erase(f[l]);
    ++l;
   }
   w.insert(f[r]);
   m = max(m, r - l + 1);
  }
  cout << m << '\n';
 }
}