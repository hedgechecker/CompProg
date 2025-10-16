#include <bits/stdc++.h>
using namespace std;
int main(){
 int n,l,m,s,o,z;
 string a;
 ios::sync_with_stdio(0);cin.tie(0);
 for(cin>>n;n--;){
  cin>>l;m=l/2;s=l/4;o=0;z=l-1;
   while(o+1!=z){
    cout<<"READ "<<m<<"\n"<<flush;cin>>a;
    if(a=="true")o=m,m+=s;else z=m,m-=s;
    s=s%2+s/2;
    }  
    cout<<"OUTPUT "<<o<<"\n"<<flush;
    }
}